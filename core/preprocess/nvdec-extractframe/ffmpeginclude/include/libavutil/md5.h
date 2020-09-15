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
 * copyright (c) 2006 Michael Niedermayer <michaelni@gmx.at>
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
 * @ingroup lavu_md5
 * Public header for MD5 hash function implementation.
 */

#ifndef AVUTIL_MD5_H
#define AVUTIL_MD5_H

#include <stddef.h>
#include <stdint.h>

#include "attributes.h"
#include "version.h"

/**
 * @defgroup lavu_md5 MD5
 * @ingroup lavu_hash
 * MD5 hash function implementation.
 *
 * @{
 */

extern const int av_md5_size;

struct AVMD5;

/**
 * Allocate an AVMD5 context.
 */
struct AVMD5 *av_md5_alloc(void);

/**
 * Initialize MD5 hashing.
 *
 * @param ctx pointer to the function context (of size av_md5_size)
 */
void av_md5_init(struct AVMD5 *ctx);

/**
 * Update hash value.
 *
 * @param ctx hash function context
 * @param src input data to update hash with
 * @param len input data length
 */
#if FF_API_CRYPTO_SIZE_T
void av_md5_update(struct AVMD5 *ctx, const uint8_t *src, int len);
#else
void av_md5_update(struct AVMD5 *ctx, const uint8_t *src, size_t len);
#endif

/**
 * Finish hashing and output digest value.
 *
 * @param ctx hash function context
 * @param dst buffer where output digest value is stored
 */
void av_md5_final(struct AVMD5 *ctx, uint8_t *dst);

/**
 * Hash an array of data.
 *
 * @param dst The output buffer to write the digest into
 * @param src The data to hash
 * @param len The length of the data, in bytes
 */
#if FF_API_CRYPTO_SIZE_T
void av_md5_sum(uint8_t *dst, const uint8_t *src, const int len);
#else
void av_md5_sum(uint8_t *dst, const uint8_t *src, size_t len);
#endif

/**
 * @}
 */

#endif /* AVUTIL_MD5_H */