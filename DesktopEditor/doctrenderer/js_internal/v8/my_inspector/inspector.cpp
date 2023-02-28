#include "inspector.h"

#include "../v8_base.h"

Inspector::Inspector(JSSmart<NSJSBase::CJSContext> context, const std::string& script)
	: jscontext_(context)
	, script_(script)
{
	context_ = context->m_internal->m_context;
	websocket_server_ = std::unique_ptr<WebSocketServer>(
			new WebSocketServer(
					port_,
					std::bind(&Inspector::onMessage, this, std::placeholders::_1)
				)
			);
	inspector_client_ = std::unique_ptr<V8InspectorClientImpl>(
			new V8InspectorClientImpl(
					CV8Worker::getInitializer().getPlatform(),
					context_,
					std::bind(&Inspector::sendMessage, this, std::placeholders::_1),
					std::bind(&Inspector::waitForFrontendMessage, this)
				)
			);
}

void Inspector::onMessage(const std::string& message) {
//	std::cout << "CDT message: " << message << std::endl;
	v8_inspector::StringView protocolMessage = convertToStringView(message);
	inspector_client_->dispatchProtocolMessage(protocolMessage);

	v8::Local<v8::Object> jsonObject = parseJson(context_, message);
	if (!jsonObject.IsEmpty()) {
		std::string method = getPropertyFromJson(context_->GetIsolate(), jsonObject, "method");
		if (method == "Runtime.runIfWaitingForDebugger") {
			inspector_client_->schedulePauseOnNextStatement(convertToStringView("For testing purpose!"));
//			inspector_client_->waitFrontendMessageOnPause();
			for (auto listener : listeners_) {
				listener->onConnected(jscontext_, script_);
			}
		}
	}
}

void Inspector::sendMessage(const std::string& message) {
//	std::cout << "Message to frontend: " << message << std::endl;
	websocket_server_->sendMessage(message);
}

void Inspector::startAgent() {
	websocket_server_->run();
}

int Inspector::waitForFrontendMessage() {
	websocket_server_->waitForFrontendMessageOnPause();
	return 1;
}

void Inspector::addListener(V8InspectorListener* listener) {
	listeners_.emplace_back(listener);
}
