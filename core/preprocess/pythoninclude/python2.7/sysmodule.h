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


/* System module interface */

#ifndef Py_SYSMODULE_H
#define Py_SYSMODULE_H
#ifdef __cplusplus
extern "C" {
#endif

PyAPI_FUNC(PyObject *) PySys_GetObject(char *);
PyAPI_FUNC(int) PySys_SetObject(char *, PyObject *);
PyAPI_FUNC(FILE *) PySys_GetFile(char *, FILE *);
PyAPI_FUNC(void) PySys_SetArgv(int, char **);
PyAPI_FUNC(void) PySys_SetArgvEx(int, char **, int);
PyAPI_FUNC(void) PySys_SetPath(char *);

PyAPI_FUNC(void) PySys_WriteStdout(const char *format, ...)
   Py_GCC_ATTRIBUTE((format(printf, 1, 2)));
PyAPI_FUNC(void) PySys_WriteStderr(const char *format, ...)
   Py_GCC_ATTRIBUTE((format(printf, 1, 2)));

PyAPI_FUNC(void) PySys_ResetWarnOptions(void);
PyAPI_FUNC(void) PySys_AddWarnOption(char *);
PyAPI_FUNC(int) PySys_HasWarnOptions(void);

PyAPI_FUNC(size_t) _PySys_GetSizeOf(PyObject *);

#ifdef __cplusplus
}
#endif
#endif /* !Py_SYSMODULE_H */
