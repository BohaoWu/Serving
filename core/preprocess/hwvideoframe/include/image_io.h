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

/*******************************************
 *
 * Copyright (c) 2020 Baidu.com, Inc. All Rights Reserved
 *
 ******************************************/
/**
 * @file image_io.h
 * @author yinyijun@baidu.com
 * @date 2020-06-08
 **/

#ifndef BAIDU_CVPRE_IMAGE_IO_H
#define BAIDU_CVPRE_IMAGE_IO_H

#include <memory>
#include <npp.h>
#include <pybind11/numpy.h>

#include "op_context.h"

// Input operator that copy numpy data to gpu buffer
class Image2Gpubuffer {
public:
    std::shared_ptr<OpContext> operator()(pybind11::array_t<float> array);
};

// Output operator that copy gpu buffer data to numpy
class Gpubuffer2Image {
public:
    pybind11::array_t<float> operator()(std::shared_ptr<OpContext> input);
};

#endif // BAIDU_CVPRE_IMAGE_IO_H
