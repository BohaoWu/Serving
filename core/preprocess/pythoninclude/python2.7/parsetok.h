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


/* Parser-tokenizer link interface */

#ifndef Py_PARSETOK_H
#define Py_PARSETOK_H
#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    int error;
    const char *filename;
    int lineno;
    int offset;
    char *text;
    int token;
    int expected;
} perrdetail;

#if 0
#define PyPARSE_YIELD_IS_KEYWORD 0x0001
#endif

#define PyPARSE_DONT_IMPLY_DEDENT 0x0002

#if 0
#define PyPARSE_WITH_IS_KEYWORD  0x0003
#endif

#define PyPARSE_PRINT_IS_FUNCTION       0x0004
#define PyPARSE_UNICODE_LITERALS        0x0008



PyAPI_FUNC(node *) PyParser_ParseString(const char *, grammar *, int,
                                              perrdetail *);
PyAPI_FUNC(node *) PyParser_ParseFile (FILE *, const char *, grammar *, int,
                                             char *, char *, perrdetail *);

PyAPI_FUNC(node *) PyParser_ParseStringFlags(const char *, grammar *, int,
                                              perrdetail *, int);
PyAPI_FUNC(node *) PyParser_ParseFileFlags(FILE *, const char *, grammar *,
       int, char *, char *,
       perrdetail *, int);
PyAPI_FUNC(node *) PyParser_ParseFileFlagsEx(FILE *, const char *, grammar *,
       int, char *, char *,
       perrdetail *, int *);

PyAPI_FUNC(node *) PyParser_ParseStringFlagsFilename(const char *,
           const char *,
           grammar *, int,
                                              perrdetail *, int);
PyAPI_FUNC(node *) PyParser_ParseStringFlagsFilenameEx(const char *,
           const char *,
           grammar *, int,
                                              perrdetail *, int *);

/* Note that he following function is defined in pythonrun.c not parsetok.c. */
PyAPI_FUNC(void) PyParser_SetError(perrdetail *);

#ifdef __cplusplus
}
#endif
#endif /* !Py_PARSETOK_H */
