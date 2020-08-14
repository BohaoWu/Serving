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


/* Range object interface */

#ifndef Py_RANGEOBJECT_H
#define Py_RANGEOBJECT_H
#ifdef __cplusplus
extern "C" {
#endif

/* This is about the type 'xrange', not the built-in function range(), which
   returns regular lists. */

/*
A range object represents an integer range.  This is an immutable object;
a range cannot change its value after creation.

Range objects behave like the corresponding tuple objects except that
they are represented by a start, stop, and step datamembers.
*/

PyAPI_DATA(PyTypeObject) PyRange_Type;

#define PyRange_Check(op) (Py_TYPE(op) == &PyRange_Type)

#ifdef __cplusplus
}
#endif
#endif /* !Py_RANGEOBJECT_H */
