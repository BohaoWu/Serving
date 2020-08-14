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
    pybind11/detail/typeid.h: Compiler-independent access to type identifiers

    Copyright (c) 2016 Wenzel Jakob <wenzel.jakob@epfl.ch>

    All rights reserved. Use of this source code is governed by a
    BSD-style license that can be found in the LICENSE file.
*/

#pragma once

#include <cstdio>
#include <cstdlib>

#if defined(__GNUG__)
#include <cxxabi.h>
#endif

#include "common.h"

NAMESPACE_BEGIN(PYBIND11_NAMESPACE)
NAMESPACE_BEGIN(detail)
/// Erase all occurrences of a substring
inline void erase_all(std::string &string, const std::string &search) {
    for (size_t pos = 0;;) {
        pos = string.find(search, pos);
        if (pos == std::string::npos) break;
        string.erase(pos, search.length());
    }
}

PYBIND11_NOINLINE inline void clean_type_id(std::string &name) {
#if defined(__GNUG__)
    int status = 0;
    std::unique_ptr<char, void (*)(void *)> res {
        abi::__cxa_demangle(name.c_str(), nullptr, nullptr, &status), std::free };
    if (status == 0)
        name = res.get();
#else
    detail::erase_all(name, "class ");
    detail::erase_all(name, "struct ");
    detail::erase_all(name, "enum ");
#endif
    detail::erase_all(name, "pybind11::");
}
NAMESPACE_END(detail)

/// Return a string representation of a C++ type
template <typename T> static std::string type_id() {
    std::string name(typeid(T).name());
    detail::clean_type_id(name);
    return name;
}

NAMESPACE_END(PYBIND11_NAMESPACE)
