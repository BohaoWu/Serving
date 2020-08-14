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


#ifndef AVUTIL_HWCONTEXT_CUDA_H
#define AVUTIL_HWCONTEXT_CUDA_H

#ifndef CUDA_VERSION
#include <cuda.h>
#endif

#include "pixfmt.h"

/**
 * @file
 * An API-specific header for AV_HWDEVICE_TYPE_CUDA.
 *
 * This API supports dynamic frame pools. AVHWFramesContext.pool must return
 * AVBufferRefs whose data pointer is a CUdeviceptr.
 */

typedef struct AVCUDADeviceContextInternal AVCUDADeviceContextInternal;

/**
 * This struct is allocated as AVHWDeviceContext.hwctx
 */
typedef struct AVCUDADeviceContext {
    CUcontext cuda_ctx;
    CUstream stream;
    AVCUDADeviceContextInternal *internal;
} AVCUDADeviceContext;

/**
 * AVHWFramesContext.hwctx is currently not used
 */

#endif /* AVUTIL_HWCONTEXT_CUDA_H */
