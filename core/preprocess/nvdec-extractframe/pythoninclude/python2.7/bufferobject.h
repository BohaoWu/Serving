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


/* Buffer object interface */

/* Note: the object's structure is private */

#ifndef Py_BUFFEROBJECT_H
#define Py_BUFFEROBJECT_H
#ifdef __cplusplus
extern "C" {
#endif


PyAPI_DATA(PyTypeObject) PyBuffer_Type;

#define PyBuffer_Check(op) (Py_TYPE(op) == &PyBuffer_Type)

#define Py_END_OF_BUFFER (-1)

PyAPI_FUNC(PyObject *) PyBuffer_FromObject(PyObject *base,
                                           Py_ssize_t offset, Py_ssize_t size);
PyAPI_FUNC(PyObject *) PyBuffer_FromReadWriteObject(PyObject *base,
                                                    Py_ssize_t offset,
                                                    Py_ssize_t size);

PyAPI_FUNC(PyObject *) PyBuffer_FromMemory(void *ptr, Py_ssize_t size);
PyAPI_FUNC(PyObject *) PyBuffer_FromReadWriteMemory(void *ptr, Py_ssize_t size);

PyAPI_FUNC(PyObject *) PyBuffer_New(Py_ssize_t size);

#ifdef __cplusplus
}
#endif
#endif /* !Py_BUFFEROBJECT_H */