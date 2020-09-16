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
 * @file ExtractFrameJpeg.h
 * @author yinyijun@baidu.com
 * @date 2020-06-01
 **/
#include "rgb_swap.h"

#include <npp.h>
#include "utils.h"

const int SwapChannel::_ORDER[CHANNEL_SIZE] = {2, 1, 0};

std::shared_ptr<OpContext> SwapChannel::operator()(std::shared_ptr<OpContext> input) {
    NppStatus ret = nppiSwapChannels_32f_C3IR(input->p_frame(), input->step(), input->nppi_size(), _ORDER);
    verify_npp_ret("nppiSwapChannels_32f_C3IR", ret);
    return input;
}
