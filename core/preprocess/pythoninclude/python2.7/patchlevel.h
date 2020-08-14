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


/* Newfangled version identification scheme.

   This scheme was added in Python 1.5.2b2; before that time, only PATCHLEVEL
   was available.  To test for presence of the scheme, test for
   defined(PY_MAJOR_VERSION).

   When the major or minor version changes, the VERSION variable in
   configure.ac must also be changed.

   There is also (independent) API version information in modsupport.h.
*/

/* Values for PY_RELEASE_LEVEL */
#define PY_RELEASE_LEVEL_ALPHA 0xA
#define PY_RELEASE_LEVEL_BETA 0xB
#define PY_RELEASE_LEVEL_GAMMA 0xC     /* For release candidates */
#define PY_RELEASE_LEVEL_FINAL 0xF /* Serial should be 0 here */
     /* Higher for patch releases */

/* Version parsed out into numeric values */
/*--start constants--*/
#define PY_MAJOR_VERSION 2
#define PY_MINOR_VERSION 7
#define PY_MICRO_VERSION 13
#define PY_RELEASE_LEVEL PY_RELEASE_LEVEL_FINAL
#define PY_RELEASE_SERIAL 0

/* Version as a string */
#define PY_VERSION       "2.7.13"
/*--end constants--*/

/* Subversion Revision number of this file (not of the repository). Empty
   since Mercurial migration. */
#define PY_PATCHLEVEL_REVISION  ""

/* Version as a single 4-byte hex number, e.g. 0x010502B2 == 1.5.2b2.
   Use this for numeric comparisons, e.g. #if PY_VERSION_HEX >= ... */
#define PY_VERSION_HEX ((PY_MAJOR_VERSION << 24) | \
   (PY_MINOR_VERSION << 16) | \
   (PY_MICRO_VERSION <<  8) | \
   (PY_RELEASE_LEVEL <<  4) | \
   (PY_RELEASE_SERIAL << 0))
