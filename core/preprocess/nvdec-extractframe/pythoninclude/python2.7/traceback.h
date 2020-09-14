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


#ifndef Py_TRACEBACK_H
#define Py_TRACEBACK_H
#ifdef __cplusplus
extern "C" {
#endif

struct _frame;

/* Traceback interface */

typedef struct _traceback {
 PyObject_HEAD
 struct _traceback *tb_next;
 struct _frame *tb_frame;
 int tb_lasti;
 int tb_lineno;
} PyTracebackObject;

PyAPI_FUNC(int) PyTraceBack_Here(struct _frame *);
PyAPI_FUNC(int) PyTraceBack_Print(PyObject *, PyObject *);
PyAPI_FUNC(int) _Py_DisplaySourceLine(PyObject *, const char *, int, int);

/* Reveal traceback type so we can typecheck traceback objects */
PyAPI_DATA(PyTypeObject) PyTraceBack_Type;
#define PyTraceBack_Check(v) (Py_TYPE(v) == &PyTraceBack_Type)

#ifdef __cplusplus
}
#endif
#endif /* !Py_TRACEBACK_H */
