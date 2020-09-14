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

#ifndef AVCODEC_ADTS_PARSER_H
#define AVCODEC_ADTS_PARSER_H

#include <stddef.h>
#include <stdint.h>

#define AV_AAC_ADTS_HEADER_SIZE 7

/**
 * Extract the number of samples and frames from AAC data.
 * @param[in]  buf     pointer to AAC data buffer
 * @param[out] samples Pointer to where number of samples is written
 * @param[out] frames  Pointer to where number of frames is written
 * @return Returns 0 on success, error code on failure.
 */
int av_adts_header_parse(const uint8_t *buf, uint32_t *samples,
                         uint8_t *frames);

#endif /* AVCODEC_ADTS_PARSER_H */
