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

#ifndef STRING_UTIL_HPP_
#define STRING_UTIL_HPP_

#include <string>
#include <vector>

namespace string_util {

std::vector<std::string> split(const std::string& str, const std::string& delim) {

    if (str.empty()) { return {}; }

    const size_t DelimSize = delim.size();

    std::vector<std::string> ret;

    std::string::size_type pos = 0;
    while (pos != std::string::npos) {
        const auto nextPos = str.find(delim, pos);
        if (nextPos == std::string::npos){
            ret.push_back(str.substr(pos));
            break;
        } else {
            ret.push_back(str.substr(pos, nextPos - pos));
        }
        pos = nextPos + DelimSize;
    }
    return ret;
}

}
#endif