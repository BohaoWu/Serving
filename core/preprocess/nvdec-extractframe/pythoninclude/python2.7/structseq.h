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


/* Tuple object interface */

#ifndef Py_STRUCTSEQ_H
#define Py_STRUCTSEQ_H
#ifdef __cplusplus
extern "C" {
#endif

typedef struct PyStructSequence_Field {
 char *name;
 char *doc;
} PyStructSequence_Field;

typedef struct PyStructSequence_Desc {
 char *name;
 char *doc;
 struct PyStructSequence_Field *fields;
 int n_in_sequence;
} PyStructSequence_Desc;

extern char* PyStructSequence_UnnamedField;

PyAPI_FUNC(void) PyStructSequence_InitType(PyTypeObject *type,
        PyStructSequence_Desc *desc);

PyAPI_FUNC(PyObject *) PyStructSequence_New(PyTypeObject* type);

typedef struct {
 PyObject_VAR_HEAD
 PyObject *ob_item[1];
} PyStructSequence;

/* Macro, *only* to be used to fill in brand new objects */
#define PyStructSequence_SET_ITEM(op, i, v) \
 (((PyStructSequence *)(op))->ob_item[i] = v)

#ifdef __cplusplus
}
#endif
#endif /* !Py_STRUCTSEQ_H */
