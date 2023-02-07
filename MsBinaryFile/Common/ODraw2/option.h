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

#include <boost/optional.hpp>
#include "../../../OOXML/Base/Types_32.h"
#include "../../../OOXML/Common/ComplexTypes.h"


namespace ODRAW
{
    struct _textPath
    {
        bool bEnabled = false;
        boost::optional<bool> bFitPath;
        boost::optional<bool> bFitShape;
        boost::optional<bool> bTrim;
        boost::optional<std::wstring> sStyle;
    };
    struct _3dOptions
    {
        _3dOptions();

        bool bEnabled;
        bool bMetallic;
        bool bExtrusionColor;
        bool bLightFace;

        bool bConstrainRotation;
        bool bRotationCenterAuto;
        bool bParallel;
        bool bKeyHarsh;
        bool bFillHarsh;

        boost::optional<double> dSpecularAmt;
        boost::optional<double> dDiffuseAmt;
        boost::optional<double> dShininess;
        _INT32 nEdgeThickness;
        _INT32 nExtrudeForward;
        _INT32 nExtrudeBackward;

        boost::optional<double> dBottomBevelWidth;
        boost::optional<double> dBottomBevelHeight;
        boost::optional<_INT32> nBottomBevelType;

        boost::optional<double> dTopBevelWidth;
        boost::optional<double> dTopBevelHeight;
        boost::optional<_INT32> nTopBevelType;

        boost::optional<double> dXRotationAngle;
        boost::optional<double> dYRotationAngle;
        boost::optional<double> dRotationAxisX;
        boost::optional<double> dRotationAxisY;
        boost::optional<double> dRotationAxisZ;
        boost::optional<double> dRotationAngle;
        boost::optional<double> dRotationCenterX;
        boost::optional<double> dRotationCenterY;
        boost::optional<double> dRotationCenterZ;

        boost::optional<double> dTolerance;
        double dXViewpoint;
        double dYViewpoint;
        boost::optional<double> dZViewpoint;

        boost::optional<ComplexTypes::Word::CColor> oExtrusionColor;
        boost::optional<ComplexTypes::Word::CColor> oCrMod;
        boost::optional<ComplexTypes::Word::CColor> oExtrusionColorExt;
        boost::optional<_INT32> nTypeExtrusionColorExt;

        _INT32 nRenderMode;

        double dOriginX;
        double dOriginY;
        double dSkewAngle;
        _INT32 nSkewAmount;

        boost::optional<double> dAmbientIntensity;
        boost::optional<double> dKeyIntensity;
        double dKeyX;
        double dKeyY;
        double dFillIntensity;
        double dFillX;
        double dFillY;
        boost::optional<double> dKeyZ;
        boost::optional<double> dFillZ;
    };
}
