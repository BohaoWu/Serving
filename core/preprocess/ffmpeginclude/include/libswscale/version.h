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

#ifndef SWSCALE_VERSION_H
#define SWSCALE_VERSION_H

/**
 * @file
 * swscale version macros
 */

#include "libavutil/version.h"

#define LIBSWSCALE_VERSION_MAJOR   5
#define LIBSWSCALE_VERSION_MINOR   2
#define LIBSWSCALE_VERSION_MICRO 100

#define LIBSWSCALE_VERSION_INT  AV_VERSION_INT(LIBSWSCALE_VERSION_MAJOR, \
                                               LIBSWSCALE_VERSION_MINOR, \
                                               LIBSWSCALE_VERSION_MICRO)
#define LIBSWSCALE_VERSION      AV_VERSION(LIBSWSCALE_VERSION_MAJOR, \
                                           LIBSWSCALE_VERSION_MINOR, \
                                           LIBSWSCALE_VERSION_MICRO)
#define LIBSWSCALE_BUILD        LIBSWSCALE_VERSION_INT

#define LIBSWSCALE_IDENT        "SwS" AV_STRINGIFY(LIBSWSCALE_VERSION)

/**
 * FF_API_* defines may be placed below to indicate public API that will be
 * dropped at a future version bump. The defines themselves are not part of
 * the public API and may change, break or disappear at any time.
 */

#ifndef FF_API_SWS_VECTOR
#define FF_API_SWS_VECTOR            (LIBSWSCALE_VERSION_MAJOR < 6)
#endif

#endif /* SWSCALE_VERSION_H */
