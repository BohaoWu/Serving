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


/* Generator object interface */

#ifndef Py_GENOBJECT_H
#define Py_GENOBJECT_H
#ifdef __cplusplus
extern "C" {
#endif

struct _frame; /* Avoid including frameobject.h */

typedef struct {
 PyObject_HEAD
 /* The gi_ prefix is intended to remind of generator-iterator. */

 /* Note: gi_frame can be NULL if the generator is "finished" */
 struct _frame *gi_frame;

 /* True if generator is being executed. */
 int gi_running;
    
 /* The code object backing the generator */
 PyObject *gi_code;

 /* List of weak reference. */
 PyObject *gi_weakreflist;
} PyGenObject;

PyAPI_DATA(PyTypeObject) PyGen_Type;

#define PyGen_Check(op) PyObject_TypeCheck(op, &PyGen_Type)
#define PyGen_CheckExact(op) (Py_TYPE(op) == &PyGen_Type)

PyAPI_FUNC(PyObject *) PyGen_New(struct _frame *);
PyAPI_FUNC(int) PyGen_NeedsFinalizing(PyGenObject *);

#ifdef __cplusplus
}
#endif
#endif /* !Py_GENOBJECT_H */
