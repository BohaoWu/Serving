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


#ifndef Py_PYTHREAD_H
#define Py_PYTHREAD_H

typedef void *PyThread_type_lock;
typedef void *PyThread_type_sema;

#ifdef __cplusplus
extern "C" {
#endif

PyAPI_FUNC(void) PyThread_init_thread(void);
PyAPI_FUNC(long) PyThread_start_new_thread(void (*)(void *), void *);
PyAPI_FUNC(void) PyThread_exit_thread(void);
PyAPI_FUNC(long) PyThread_get_thread_ident(void);

PyAPI_FUNC(PyThread_type_lock) PyThread_allocate_lock(void);
PyAPI_FUNC(void) PyThread_free_lock(PyThread_type_lock);
PyAPI_FUNC(int) PyThread_acquire_lock(PyThread_type_lock, int);
#define WAIT_LOCK 1
#define NOWAIT_LOCK 0
PyAPI_FUNC(void) PyThread_release_lock(PyThread_type_lock);

PyAPI_FUNC(size_t) PyThread_get_stacksize(void);
PyAPI_FUNC(int) PyThread_set_stacksize(size_t);

/* Thread Local Storage (TLS) API */
PyAPI_FUNC(int) PyThread_create_key(void);
PyAPI_FUNC(void) PyThread_delete_key(int);
PyAPI_FUNC(int) PyThread_set_key_value(int, void *);
PyAPI_FUNC(void *) PyThread_get_key_value(int);
PyAPI_FUNC(void) PyThread_delete_key_value(int key);

/* Cleanup after a fork */
PyAPI_FUNC(void) PyThread_ReInitTLS(void);

#ifdef __cplusplus
}
#endif

#endif /* !Py_PYTHREAD_H */
