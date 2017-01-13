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

#ifndef __USE_OPTIONAL_HPP_
#define __USE_OPTIONAL_HPP_

#ifdef __has_include
#  if __has_include(<optional>)
#    include <optional>
#    define have_optional 1
#  elif __has_include(<experimental/optional>)
#    include <experimental/optional>
#    define have_optional 1
#    define experimental_optional
#  else
#    define have_optional 0
#    error "This file requires to use std::experimental::optional (or std::optional). Please update GCC version."
#  endif
#endif

#ifdef experimental_optional
using std::experimental::optional;
using std::experimental::make_optional;
using std::experimental::nullopt;
#else
using std::optional
using std::make_optional;
using std:::nullopt;
#endif

#endif