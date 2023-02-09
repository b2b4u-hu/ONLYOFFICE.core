/*
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

#include "PentagonType.h"

using namespace ODRAW;
// 56
CPentagonType::CPentagonType()
{
	m_bConcentricFill = true;
	m_eJoin = ODRAW::lineJoinMiter;

	m_strPath = _T("m10800,l,8259,4200,21600r13200,l21600,8259xe");
	LoadConnectorsList(_T("10800,0;0,8259;4200,21600;10800,21600;17400,21600;21600,8259"));

	m_arConnectorAngles.push_back(270);
	m_arConnectorAngles.push_back(180);
	m_arConnectorAngles.push_back(90);
	m_arConnectorAngles.push_back(90);
	m_arConnectorAngles.push_back(90);
	m_arConnectorAngles.push_back(0);

	LoadTextRect(_T("4200,5077,17400,21600"));
}
