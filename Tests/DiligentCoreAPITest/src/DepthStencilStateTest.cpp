/*     Copyright 2019 Diligent Graphics LLC
 *  
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT OF ANY PROPRIETARY RIGHTS.
 *
 *  In no event and under no legal theory, whether in tort (including negligence), 
 *  contract, or otherwise, unless required by applicable law (such as deliberate 
 *  and grossly negligent acts) or agreed to in writing, shall any Contributor be
 *  liable for any damages, including any direct, indirect, special, incidental, 
 *  or consequential damages of any character arising as a result of this License or 
 *  out of the use or inability to use the software (including but not limited to damages 
 *  for loss of goodwill, work stoppage, computer failure or malfunction, or any and 
 *  all other commercial damages or losses), even if such Contributor has been advised 
 *  of the possibility of such damages.
 */

#include "TestingEnvironment.h"
#include "PSOTestBase.h"
#include "GraphicsAccessories.h"

#include "gtest/gtest.h"

using namespace Diligent;
using namespace Diligent::Testing;

namespace
{

class DepthStencilStateTest : public PSOTestBase, public ::testing::Test
{
protected:
    static void SetUpTestSuite()
    {
        InitResources();
    }

    static void TearDownTestSuite()
    {
        ReleaseResources();
        TestingEnvironment::GetInstance()->ReleaseResources();
    }
};

TEST_F(DepthStencilStateTest, CreatePSO)
{
    auto PSODesc = GetPSODesc();

    DepthStencilStateDesc& DSSDesc = PSODesc.GraphicsPipeline.DepthStencilDesc;

    DSSDesc.DepthEnable      = False;
    DSSDesc.DepthWriteEnable = False;
    ASSERT_TRUE(CreateTestPSO(PSODesc, true));

    DSSDesc.DepthEnable = True;
    ASSERT_TRUE(CreateTestPSO(PSODesc, true));

    DSSDesc.DepthWriteEnable = True;
    ASSERT_TRUE(CreateTestPSO(PSODesc, true));

    for (auto CmpFunc = COMPARISON_FUNC_UNKNOWN + 1; CmpFunc < COMPARISON_FUNC_NUM_FUNCTIONS; ++CmpFunc)
    {
        DSSDesc.DepthFunc = static_cast<COMPARISON_FUNCTION>(CmpFunc);
        ASSERT_TRUE(CreateTestPSO(PSODesc, true)) << "Comparison func: " << GetComparisonFunctionLiteralName(DSSDesc.DepthFunc, true);
    }

    DSSDesc.StencilEnable = True;
    ASSERT_TRUE(CreateTestPSO(PSODesc, true));

    DSSDesc.StencilReadMask = 0xA9;
    ASSERT_TRUE(CreateTestPSO(PSODesc, true));

    DSSDesc.StencilWriteMask = 0xB8;
    ASSERT_TRUE(CreateTestPSO(PSODesc, true));

    for (int Face = 0; Face < 2; ++Face)
    {
        auto& FaceOp = Face == 0 ? DSSDesc.FrontFace : DSSDesc.BackFace;
        for (auto StOp = STENCIL_OP_UNDEFINED + 1; StOp < STENCIL_OP_NUM_OPS; ++StOp)
        {
            FaceOp.StencilFailOp = static_cast<STENCIL_OP>(StOp);
            ASSERT_TRUE(CreateTestPSO(PSODesc, true)) << "Face: " << Face << "; Stencil fail op: " << GetStencilOpLiteralName(FaceOp.StencilFailOp);
        }

        for (auto StOp = STENCIL_OP_UNDEFINED + 1; StOp < STENCIL_OP_NUM_OPS; ++StOp)
        {
            FaceOp.StencilDepthFailOp = static_cast<STENCIL_OP>(StOp);
            ASSERT_TRUE(CreateTestPSO(PSODesc, true)) << "Face: " << Face << "; Stencil depth fail op: " << GetStencilOpLiteralName(FaceOp.StencilDepthFailOp);
        }

        for (auto StOp = STENCIL_OP_UNDEFINED + 1; StOp < STENCIL_OP_NUM_OPS; ++StOp)
        {
            FaceOp.StencilPassOp = static_cast<STENCIL_OP>(StOp);
            ASSERT_TRUE(CreateTestPSO(PSODesc, true)) << "Face: " << Face << "; Stencil pass op: " << GetStencilOpLiteralName(FaceOp.StencilPassOp);
        }

        for (auto CmpFunc = COMPARISON_FUNC_UNKNOWN + 1; CmpFunc < COMPARISON_FUNC_NUM_FUNCTIONS; ++CmpFunc)
        {
            FaceOp.StencilFunc = static_cast<COMPARISON_FUNCTION>(CmpFunc);
            ASSERT_TRUE(CreateTestPSO(PSODesc, true)) << "Face: " << Face << "; Comparison func: " << GetComparisonFunctionLiteralName(FaceOp.StencilFunc, true);
        }
    }
}

} // namespace
