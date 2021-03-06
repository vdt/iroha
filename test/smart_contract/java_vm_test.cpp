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

#include "../../core/model/smart_contract/virtual_machine_interface.hpp"

#include <gtest/gtest.h>

using smart_contract::SmartContract;

TEST(SmartContract, createVM){

    std::string contractName = "SampleCurrency";
    std::string functionName = "remit";
    std::unordered_map<std::string, std::string> params;
    params["A"] = "Ant";
    params["B"] = "Bright";
    SmartContract smartContract = SmartContract();
    smartContract.initializeVM(contractName);
    smartContract.invokeFunction(
        contractName,
        functionName,
        params
    );
}
