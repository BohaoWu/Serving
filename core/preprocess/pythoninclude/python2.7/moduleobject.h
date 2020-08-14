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


/* Module object interface */

#ifndef Py_MODULEOBJECT_H
#define Py_MODULEOBJECT_H
#ifdef __cplusplus
extern "C" {
#endif

PyAPI_DATA(PyTypeObject) PyModule_Type;

#define PyModule_Check(op) PyObject_TypeCheck(op, &PyModule_Type)
#define PyModule_CheckExact(op) (Py_TYPE(op) == &PyModule_Type)

PyAPI_FUNC(PyObject *) PyModule_New(const char *);
PyAPI_FUNC(PyObject *) PyModule_GetDict(PyObject *);
PyAPI_FUNC(char *) PyModule_GetName(PyObject *);
PyAPI_FUNC(char *) PyModule_GetFilename(PyObject *);
PyAPI_FUNC(void) _PyModule_Clear(PyObject *);

#ifdef __cplusplus
}
#endif
#endif /* !Py_MODULEOBJECT_H */
