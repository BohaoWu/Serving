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
 * Copyright (c) 2009 Baptiste Coudurier <baptiste.coudurier@gmail.com>
 *
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

#ifndef AVUTIL_RANDOM_SEED_H
#define AVUTIL_RANDOM_SEED_H

#include <stdint.h>
/**
 * @addtogroup lavu_crypto
 * @{
 */

/**
 * Get a seed to use in conjunction with random functions.
 * This function tries to provide a good seed at a best effort bases.
 * Its possible to call this function multiple times if more bits are needed.
 * It can be quite slow, which is why it should only be used as seed for a faster
 * PRNG. The quality of the seed depends on the platform.
 */
uint32_t av_get_random_seed(void);

/**
 * @}
 */

#endif /* AVUTIL_RANDOM_SEED_H */
