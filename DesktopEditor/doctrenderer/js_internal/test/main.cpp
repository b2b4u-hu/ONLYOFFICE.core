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

#include <iostream>

#include "../../embed/ZipEmbed.h"
#include "../js_base.h"

using namespace NSJSBase;
int main(int argc, char *argv[])
{
    JSSmart<CJSContext> oContext1 = new CJSContext;
    oContext1->Initialize();

    JSSmart<CJSContext> oContext2 = new CJSContext;
    oContext2->Initialize();

    {
        // Create first context
        JSSmart<CJSIsolateScope> oIsolateScope1 = oContext1->CreateIsolateScope();
        JSSmart<CJSLocalScope>   oHandleScope1  = oContext1->CreateLocalScope();

        oContext1->CreateGlobalForContext();
        CZipEmbed::CreateObjectInContext("CZip", oContext1);

        oContext1->CreateContext();

        // Create second context
        JSSmart<CJSIsolateScope> oIsolateScope2 = oContext2->CreateIsolateScope();
        JSSmart<CJSLocalScope>   oHandleScope2  = oContext2->CreateLocalScope();

        oContext2->CreateGlobalForContext();
        CZipEmbed::CreateObjectInContext("CZip", oContext2);

        oContext2->CreateContext();

        // Enter first context
        JSSmart<CJSContextScope> oContextScope1 = oContext1->CreateContextScope();
        JSSmart<CJSObject> oGlobal1 = oContext1->GetGlobal();

        // Work with first context
        JSSmart<CJSValue> oRes1 = oContext1->runScript(
            "var oZip = new CZip;\n"
            "var files = oZip.open('" CURR_DIR "/../v8');"
            "oZip.close();"
        );

        // Enter second context
        JSSmart<CJSContextScope> oContextScope2 = oContext2->CreateContextScope();
        JSSmart<CJSObject> oGlobal2 = oContext2->GetGlobal();

        // Work with second context
        JSSmart<CJSValue> oRes2 = oContext2->runScript(
            "var oZip = new CZip;\n"
            "var files = oZip.open('" CURR_DIR "/../jsc');"
            "oZip.close();"
        );

        // Print first result
        JSSmart<CJSArray> oFiles1 = oGlobal1->get("files")->toArray();
        std::cout << "\nRESULT FROM CONTEXT 1:\n";
        for (int i = 0; i < oFiles1->getCount(); i++) {
            std::cout << oFiles1->get(i)->toStringA() << std::endl;
        }

        // Print second result
        JSSmart<CJSArray> oFiles2 = oGlobal2->get("files")->toArray();
        std::cout << "\nRESULT FROM CONTEXT 2:\n";
        for (int i = 0; i < oFiles2->getCount(); i++) {
            std::cout << oFiles2->get(i)->toStringA() << std::endl;
        }

    }

    oContext1->Dispose();
    oContext2->Dispose();

    return 0;
}
