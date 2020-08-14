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
 * Copyright (C) 2007 Michael Niedermayer <michaelni@gmx.at>
 * Copyright (C) 2013 James Almer <jamrial@gmail.com>
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

/**
 * @file
 * @ingroup lavu_ripemd
 * Public header for RIPEMD hash function implementation.
 */

#ifndef AVUTIL_RIPEMD_H
#define AVUTIL_RIPEMD_H

#include <stdint.h>

#include "attributes.h"
#include "version.h"

/**
 * @defgroup lavu_ripemd RIPEMD
 * @ingroup lavu_hash
 * RIPEMD hash function implementation.
 *
 * @{
 */

extern const int av_ripemd_size;

struct AVRIPEMD;

/**
 * Allocate an AVRIPEMD context.
 */
struct AVRIPEMD *av_ripemd_alloc(void);

/**
 * Initialize RIPEMD hashing.
 *
 * @param context pointer to the function context (of size av_ripemd_size)
 * @param bits    number of bits in digest (128, 160, 256 or 320 bits)
 * @return        zero if initialization succeeded, -1 otherwise
 */
int av_ripemd_init(struct AVRIPEMD* context, int bits);

/**
 * Update hash value.
 *
 * @param context hash function context
 * @param data    input data to update hash with
 * @param len     input data length
 */
#if FF_API_CRYPTO_SIZE_T
void av_ripemd_update(struct AVRIPEMD* context, const uint8_t* data, unsigned int len);
#else
void av_ripemd_update(struct AVRIPEMD* context, const uint8_t* data, size_t len);
#endif

/**
 * Finish hashing and output digest value.
 *
 * @param context hash function context
 * @param digest  buffer where output digest value is stored
 */
void av_ripemd_final(struct AVRIPEMD* context, uint8_t *digest);

/**
 * @}
 */

#endif /* AVUTIL_RIPEMD_H */
