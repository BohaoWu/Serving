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
 * Version macros.
 *
 * This file is part of libswresample
 *
 * libswresample is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * libswresample is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with libswresample; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef SWRESAMPLE_VERSION_H
#define SWRESAMPLE_VERSION_H

/**
 * @file
 * Libswresample version macros
 */

#include "libavutil/avutil.h"

#define LIBSWRESAMPLE_VERSION_MAJOR   3
#define LIBSWRESAMPLE_VERSION_MINOR   2
#define LIBSWRESAMPLE_VERSION_MICRO 100

#define LIBSWRESAMPLE_VERSION_INT  AV_VERSION_INT(LIBSWRESAMPLE_VERSION_MAJOR, \
                                                  LIBSWRESAMPLE_VERSION_MINOR, \
                                                  LIBSWRESAMPLE_VERSION_MICRO)
#define LIBSWRESAMPLE_VERSION      AV_VERSION(LIBSWRESAMPLE_VERSION_MAJOR, \
                                              LIBSWRESAMPLE_VERSION_MINOR, \
                                              LIBSWRESAMPLE_VERSION_MICRO)
#define LIBSWRESAMPLE_BUILD        LIBSWRESAMPLE_VERSION_INT

#define LIBSWRESAMPLE_IDENT        "SwR" AV_STRINGIFY(LIBSWRESAMPLE_VERSION)

#endif /* SWRESAMPLE_VERSION_H */
