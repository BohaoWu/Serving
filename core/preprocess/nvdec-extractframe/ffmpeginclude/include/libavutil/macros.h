// Copyright (c) 2020 PaddlePaddle Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

/**
 * @file
 * @ingroup lavu
 * Utility Preprocessor macros
 */

#ifndef AVUTIL_MACROS_H
#define AVUTIL_MACROS_H

/**
 * @addtogroup preproc_misc Preprocessor String Macros
 *
 * String manipulation macros
 *
 * @{
 */

#define AV_STRINGIFY(s)         AV_TOSTRING(s)
#define AV_TOSTRING(s) #s

#define AV_GLUE(a, b) a ## b
#define AV_JOIN(a, b) AV_GLUE(a, b)

/**
 * @}
 */

#define AV_PRAGMA(s) _Pragma(#s)

#define FFALIGN(x, a) (((x)+(a)-1)&~((a)-1))

#endif /* AVUTIL_MACROS_H */
