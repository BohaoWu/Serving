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


#ifndef Py_PYDEBUG_H
#define Py_PYDEBUG_H
#ifdef __cplusplus
extern "C" {
#endif

PyAPI_DATA(int) Py_DebugFlag;
PyAPI_DATA(int) Py_VerboseFlag;
PyAPI_DATA(int) Py_InteractiveFlag;
PyAPI_DATA(int) Py_InspectFlag;
PyAPI_DATA(int) Py_OptimizeFlag;
PyAPI_DATA(int) Py_NoSiteFlag;
PyAPI_DATA(int) Py_BytesWarningFlag;
PyAPI_DATA(int) Py_UseClassExceptionsFlag;
PyAPI_DATA(int) Py_FrozenFlag;
PyAPI_DATA(int) Py_TabcheckFlag;
PyAPI_DATA(int) Py_UnicodeFlag;
PyAPI_DATA(int) Py_IgnoreEnvironmentFlag;
PyAPI_DATA(int) Py_DivisionWarningFlag;
PyAPI_DATA(int) Py_DontWriteBytecodeFlag;
PyAPI_DATA(int) Py_NoUserSiteDirectory;
/* _XXX Py_QnewFlag should go away in 3.0.  It's true iff -Qnew is passed,
  on the command line, and is used in 2.2 by ceval.c to make all "/" divisions
  true divisions (which they will be in 3.0). */
PyAPI_DATA(int) _Py_QnewFlag;
/* Warn about 3.x issues */
PyAPI_DATA(int) Py_Py3kWarningFlag;
PyAPI_DATA(int) Py_HashRandomizationFlag;

/* this is a wrapper around getenv() that pays attention to
   Py_IgnoreEnvironmentFlag.  It should be used for getting variables like
   PYTHONPATH and PYTHONHOME from the environment */
#define Py_GETENV(s) (Py_IgnoreEnvironmentFlag ? NULL : getenv(s))

PyAPI_FUNC(void) Py_FatalError(const char *message);

#ifdef __cplusplus
}
#endif
#endif /* !Py_PYDEBUG_H */
