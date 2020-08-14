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

/*  timefuncs.h
 */

/* Utility function related to timemodule.c. */

#ifndef TIMEFUNCS_H
#define TIMEFUNCS_H
#ifdef __cplusplus
extern "C" {
#endif


/* Cast double x to time_t, but raise ValueError if x is too large
 * to fit in a time_t.  ValueError is set on return iff the return
 * value is (time_t)-1 and PyErr_Occurred().
 */
PyAPI_FUNC(time_t) _PyTime_DoubleToTimet(double x);

/* Get the current time since the epoch in seconds */
PyAPI_FUNC(double) _PyTime_FloatTime(void);


#ifdef __cplusplus
}
#endif
#endif  /* TIMEFUNCS_H */
