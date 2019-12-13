/*
* All or portions of this file Copyright (c) Amazon.com, Inc. or its affiliates or
* its licensors.
*
* For complete copyright and license terms please see the LICENSE at the root of this
* distribution (the "License"). All use of this software is governed by the License,
* or, if provided, by the license below or the license accompanying this file. Do not
* remove or modify any license notices. This file is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*
*/
// Original file Copyright Crytek GMBH or its affiliates, used under license.

#include "stdafx.h"

#include "../ImageObject.h"  // ImageToProcess

///////////////////////////////////////////////////////////////////////////////////

namespace ImageDDS
{
    ImageObject* LoadByUsingDDSLoader(const char* filenameRead, CImageProperties* pProps, string& res_specialInstructions)
    {
        res_specialInstructions.clear();
        AZ_PUSH_DISABLE_WARNING(4996, "-Wdeprecated-declarations")
        auto pRet(std::make_unique<ImageObject>(128, 128, 1, ePixelFormat_A32B32G32R32F, ImageObject::eCubemap_UnknownYet));
		AZ_POP_DISABLE_WARNING
        return pRet->LoadImage(filenameRead, false) ? pRet.release() : nullptr;
        
    }

    bool SaveByUsingDDSSaver(const char* filenameWrite, const CImageProperties* pProps, const ImageObject* pImageObject)
    {
        return pImageObject->SaveImage(filenameWrite, false);
    }
}
