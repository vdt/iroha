/*
Copyright Soramitsu Co., Ltd. 2016 All Rights Reserved.

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

#ifndef __ASSERT_HPP_
#define __ASSERT_HPP_

#include "logger.hpp"

#define IROHA_ASSERT_TRUE(condition, lggr) \
    if (! (condition) ) { lggr; exit(EXIT_FAILURE); }

#define IROHA_ASSERT_FALSE(condition, lggr) \
    if ( (condition) )  { lggr; exit(EXIT_FAILURE); }

#define IROHA_FATAL(lggr) \
    { lggr; exit(EXIT_FAILURE); }

#define IROHA_NO_ARRIVAL(where)  \
    { logger::fatal(where) << "The code should not arrive here."; exit(EXIT_FAILURE); }

#endif
