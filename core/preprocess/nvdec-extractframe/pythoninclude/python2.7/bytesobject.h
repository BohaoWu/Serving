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

#define PyBytesObject PyStringObject
#define PyBytes_Type PyString_Type

#define PyBytes_Check PyString_Check
#define PyBytes_CheckExact PyString_CheckExact 
#define PyBytes_CHECK_INTERNED PyString_CHECK_INTERNED
#define PyBytes_AS_STRING PyString_AS_STRING
#define PyBytes_GET_SIZE PyString_GET_SIZE
#define Py_TPFLAGS_BYTES_SUBCLASS Py_TPFLAGS_STRING_SUBCLASS

#define PyBytes_FromStringAndSize PyString_FromStringAndSize
#define PyBytes_FromString PyString_FromString
#define PyBytes_FromFormatV PyString_FromFormatV
#define PyBytes_FromFormat PyString_FromFormat
#define PyBytes_Size PyString_Size
#define PyBytes_AsString PyString_AsString
#define PyBytes_Repr PyString_Repr
#define PyBytes_Concat PyString_Concat
#define PyBytes_ConcatAndDel PyString_ConcatAndDel
#define _PyBytes_Resize _PyString_Resize
#define _PyBytes_Eq _PyString_Eq
#define PyBytes_Format PyString_Format
#define _PyBytes_FormatLong _PyString_FormatLong
#define PyBytes_DecodeEscape PyString_DecodeEscape
#define _PyBytes_Join _PyString_Join
#define PyBytes_AsStringAndSize PyString_AsStringAndSize
#define _PyBytes_InsertThousandsGrouping _PyString_InsertThousandsGrouping
