/*
   Copyright 2024 Ryan "rj45" Sanche

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/
#include "ux/ux.h"

#define STB_DS_IMPLEMENTATION
#include "stb_ds.h"

#define SOKOL_IMPL
#include "sokol_time.h"

#include "utest.h"

#ifndef _WIN32
#include "stacktrace.h"
#endif

#define STRPOOL_IMPLEMENTATION
#include "strpool.h"

UTEST_STATE();
int main(int argc, const char *const argv[]) {

#ifndef _WIN32
  init_exceptions((char *)argv[0]);
#endif
  ux_global_init();
  return utest_main(argc, argv);
}