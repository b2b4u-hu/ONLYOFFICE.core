﻿/*
 * (c) Copyright Ascensio System SIA 2010-2019
 *
 * This program is a free software product. You can redistribute it and/or
 * modify it under the terms of the GNU Affero General Public License (AGPL)
 * version 3 as published by the Free Software Foundation. In accordance with
 * Section 7(a) of the GNU AGPL its Section 15 shall be amended to the effect
 * that Ascensio System SIA expressly excludes the warranty of non-infringement
 * of any third-party rights.
 *
 * This program is distributed WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR  PURPOSE. For
 * details, see the GNU AGPL at: http://www.gnu.org/licenses/agpl-3.0.html
 *
 * You can contact Ascensio System SIA at 20A-12 Ernesta Birznieka-Upisha
 * street, Riga, Latvia, EU, LV-1050.
 *
 * The  interactive user interfaces in modified source and object code versions
 * of the Program must display Appropriate Legal Notices, as required under
 * Section 5 of the GNU AGPL version 3.
 *
 * Pursuant to Section 7(b) of the License you must retain the original Product
 * logo when distributing the program. Pursuant to Section 7(e) we decline to
 * grant you any rights under trademark law for use of our trademarks.
 *
 * All the Product's GUI elements, including illustrations and icon sets, as
 * well as technical writing content are licensed under the terms of the
 * Creative Commons Attribution-ShareAlike 4.0 International. See the License
 * terms at http://creativecommons.org/licenses/by-sa/4.0/legalcode
 *
 */

#include "ixwebsocket_internal.h"

void CIXWebSocket::open()
{
    ix::SocketTLSOptions tls;
    tls.caFile = "NONE";//std::string(this->m_pInternal->m_sAssetsCertificateSSL.begin(), this->m_pInternal->m_sAssetsCertificateSSL.end());
    webSocket.setTLSOptions(tls);
    webSocket.setUrl(url);
    std::function<void(const ix::WebSocketMessagePtr&)> f = std::bind(&CIXWebSocket::receive, this, std::placeholders::_1);
    webSocket.setOnMessageCallback(f);
    webSocket.start();
}

void CIXWebSocket::receive(const ix::WebSocketMessagePtr& msg)
{
    if (msg->type == ix::WebSocketMessageType::Message)
    {
        listener->onMessage(msg->str);
    }
    else if (msg->type == ix::WebSocketMessageType::Open)
    {
        listener->onOpen();
    }
    else if (msg->type == ix::WebSocketMessageType::Error)
    {
        listener->onError(msg->errorInfo.reason);
    }
    else if (msg->type == ix::WebSocketMessageType::Close)
    {
        listener->onClose(msg->closeInfo.code, msg->closeInfo.reason);
    }
}

void CIXWebSocket::send(std::string message)
{
    webSocket.send(message);
}

void CIXWebSocket::close()
{
    webSocket.stop();
}