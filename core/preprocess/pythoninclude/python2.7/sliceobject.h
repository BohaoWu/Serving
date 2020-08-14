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

#ifndef Py_SLICEOBJECT_H
#define Py_SLICEOBJECT_H
#ifdef __cplusplus
extern "C" {
#endif

/* The unique ellipsis object "..." */

PyAPI_DATA(PyObject) _Py_EllipsisObject; /* Don't use this directly */

#define Py_Ellipsis (&_Py_EllipsisObject)

/* Slice object interface */

/*

A slice object containing start, stop, and step data members (the
names are from range).  After much talk with Guido, it was decided to
let these be any arbitrary python type.  Py_None stands for omitted values.
*/

typedef struct {
    PyObject_HEAD
    PyObject *start, *stop, *step; /* not NULL */
} PySliceObject;

PyAPI_DATA(PyTypeObject) PySlice_Type;
PyAPI_DATA(PyTypeObject) PyEllipsis_Type;

#define PySlice_Check(op) (Py_TYPE(op) == &PySlice_Type)

PyAPI_FUNC(PyObject *) PySlice_New(PyObject* start, PyObject* stop,
                                  PyObject* step);
PyAPI_FUNC(PyObject *) _PySlice_FromIndices(Py_ssize_t start, Py_ssize_t stop);
PyAPI_FUNC(int) PySlice_GetIndices(PySliceObject *r, Py_ssize_t length,
                                  Py_ssize_t *start, Py_ssize_t *stop, Py_ssize_t *step);
PyAPI_FUNC(int) PySlice_GetIndicesEx(PySliceObject *r, Py_ssize_t length,
        Py_ssize_t *start, Py_ssize_t *stop, 
        Py_ssize_t *step, Py_ssize_t *slicelength);

#ifdef __cplusplus
}
#endif
#endif /* !Py_SLICEOBJECT_H */
