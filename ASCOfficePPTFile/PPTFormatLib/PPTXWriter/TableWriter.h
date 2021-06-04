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
#pragma once

#include "../../../ASCOfficePPTXFile/PPTXFormat/Logic/GraphicFrame.h"
#include "../../../ASCOfficePPTXFile/Editor/Drawing/Elements.h"

namespace PPT_FORMAT
{
class TableWriter
{
public:
    TableWriter(CTableElement *pTableElement);

    void Convert(PPTX::Logic::GraphicFrame& oGraphicFrame);

private:
    void FillNvGraphicFramePr(PPTX::Logic::NvGraphicFramePr& oNvGFPr);
    void FillXfrm(PPTX::Logic::Xfrm& oXFRM);
    void FillTable(PPTX::Logic::Table &oTable);
    
    std::vector<int> getWidth(std::vector<CShapeElement *> &arrCells);
    std::vector<std::vector<CShapeElement *> >
        getRows(std::vector<CShapeElement *> &arrCells);
    int getCellHeight(const CShapeElement * pCell)const;

    void FillTblPr(PPTX::Logic::TableProperties& oTblPr);
    void FillTblGrid(std::vector<PPTX::Logic::TableCol>& tblGrid,
                     std::vector<CShapeElement *> &arrCells);
    void prepareShapes(std::vector<CShapeElement*> &arrCells,
                       std::vector<CShapeElement*>& arrSpliters);
    std::vector<std::vector<CElement*> >
        createProtoTable(std::vector<CShapeElement *> &arrCells);

    void FillRow(PPTX::Logic::TableRow& oRow, std::vector<CShapeElement*>& arrCells);

private:
    CTableElement *m_pTableElement;
};
}
