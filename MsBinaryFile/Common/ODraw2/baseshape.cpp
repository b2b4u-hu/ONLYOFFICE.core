#include "baseshape.h"


using namespace ODRAW;

BaseShape::BaseShape()
{

}

bool BaseShape::LoadFromXML(const std::wstring &xml)
{
    XmlUtils::CXmlNode oNodePict;
    if (oNodePict.FromXmlString(xml))
    {
        return LoadFromXML(oNodePict);
    }
    return false;
}

bool BaseShape::LoadFromXML(XmlUtils::CXmlNode &xmlNode)
{
    XmlUtils::CXmlNode avLst;
    bool res = true;
    if(xmlNode.GetNode(_T("avLst"), avLst))
        res &= LoadAdjustValuesList(avLst.GetXml());

    XmlUtils::CXmlNode gdLst;
    if(xmlNode.GetNode(_T("gdLst"), gdLst))
        res &= LoadGuidesList(gdLst.GetXml());

    XmlUtils::CXmlNode ahLst;
    if(xmlNode.GetNode(_T("ahLst"), ahLst))
        res &= LoadAdjustHandlesList(ahLst.GetXml());

    XmlUtils::CXmlNode cxnLst;
    if(xmlNode.GetNode(_T("cxnLst"), cxnLst))
        res &= LoadConnectorsList(cxnLst.GetXml());

    XmlUtils::CXmlNode textRect;
    if(xmlNode.GetNode(_T("rect"), textRect))
    {
        strRect = textRect.GetXml();
        res &= LoadTextRect(strRect);
    }

    XmlUtils::CXmlNode pathLst;
    if(xmlNode.GetNode(_T("pathLst"), pathLst))
    {
        strPath = pathLst.GetXml();
        res &= LoadPathList(strPath);
    }

    return res;
}

bool BaseShape::LoadAdjustValuesList(const std::wstring &xml)
{
    std::wstring strXml = xml;
    if (0 == strXml.find((wchar_t)','))
        strXml = (_T("defaultAdj") + strXml);

    LONG lLastIndex = (LONG)strXml.length() - 1;

    if (lLastIndex >= 0 && lLastIndex == strXml.rfind((wchar_t)','))
    {
        strXml = strXml + _T("defaultAdj");
    }
    ReplaceAll(strXml, L",,", L",defaultAdj,");

    std::vector<std::wstring> arAdj;
    boost::algorithm::split(arAdj, strXml, boost::algorithm::is_any_of(L","), boost::algorithm::token_compress_on);

    std::vector<long> oOldAdj;
    size_t nOldLen = arAbsAdjustments.size();

    for (size_t ii = 0; ii < nOldLen; ++ii)
        oOldAdj.push_back(arAbsAdjustments[ii]);

    arAbsAdjustments.clear();
    for (size_t nIndex = 0; nIndex < arAdj.size(); ++nIndex)
    {
        if (_T("defaultAdj") == arAdj[nIndex])
        {
            if (nIndex >= nOldLen)
                arAbsAdjustments.push_back(0);
            else
                arAbsAdjustments.push_back(oOldAdj[nIndex]);
        }
        else
        {
            long val = (long)XmlUtils::GetInteger(arAdj[nIndex]);
            if (nIndex < arAbsMaxAdjustments.size())
            {
                if (abs(val) > arAbsMaxAdjustments[nIndex])
                    val = 0;
            }
            arAbsAdjustments.push_back(val);
        }
    }

    size_t newLen = arAbsAdjustments.size();

    for (size_t i = newLen; i < nOldLen; ++i)
    {
        arAbsAdjustments.push_back(oOldAdj[i]);
    }
    return true;
}

bool BaseShape::LoadGuidesList(const std::wstring &xml)
{

}

bool BaseShape::LoadAdjustHandlesList(const std::wstring &xml)
{

}

bool BaseShape::LoadConnectorsList(const std::wstring &xml)
{

}

bool BaseShape::LoadTextRect(const std::wstring &xml)
{

}

bool BaseShape::LoadPathList(const std::wstring &xml)
{

}

bool BaseShape::SetAdjustment(long index, long value)
{

}

void BaseShape::ReCalculate()
{

}
