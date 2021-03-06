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

#pragma once

#include <cstdint>
#include <string>

namespace Diligent
{

using Float32 = float; ///< 32-bit float

using Int64 = int64_t; ///< 64-bit signed integer
using Int32 = int32_t; ///< 32-bit signed integer
using Int16 = int16_t; ///< 16-bit signed integer
using Int8  = int8_t;  ///< 8-bit signed integer

using Uint64 = uint64_t; ///< 64-bit unsigned integer
using Uint32 = uint32_t; ///< 32-bit unsigned integer
using Uint16 = uint16_t; ///< 16-bit unsigned integer
using Uint8  = uint8_t;  ///< 8-bit unsigned integer

using SizeType = size_t;
using PVoid    = void*;
using CPVoid   = const void*;

using Bool                  = bool; ///< Boolean
static constexpr Bool False = false;
static constexpr Bool True  = true;

using Char   = char;
using String = std::basic_string<Char>; ///< String variable

} // namespace Diligent
