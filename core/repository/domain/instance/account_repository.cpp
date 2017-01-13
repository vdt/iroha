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

#include "../../../infra/protobuf/convertor.hpp"

#include "../../../model/state/account.hpp"

#include "../account_repository.hpp"
#include "../../world_state_repository.hpp"

#include "../../../util/use_optional.hpp"
#include "../../../util/assert.hpp"

namespace repository{
    namespace account {

        // SampleAsset has only quantity no logic, so this value is int.
        bool update_quantity(
            const std::string&  uuid,
            const std::string&  assetName,
            std::int64_t        newValue
        ){
            Event::Account protoAccount;

            if (auto account = world_state_repository::find(uuid)) {
                protoAccount.ParseFromString(*account);
            } else {
                IROHA_FATAL(
                    logger::fatal("account repository") << "account is invalid."
                );
            }

            for (int i = 0;i < protoAccount.assets_size(); i++) {
                if (protoAccount.assets(i).name() == assetName) {
                    protoAccount.mutable_assets(i)->set_value(newValue);
                }
            }

            std::string strAccount;
            protoAccount.SerializeToString(&strAccount);
            world_state_repository::update(uuid, strAccount);
        }

        optional<object::Account> findByUuid(const std::string& uuid) {
            auto serializedAccount = world_state_repository::find(uuid);
            auto account = world_state_repository::find(uuid);
            if (account != nullopt) {
                logger::debug("AccountRepository") << " data:" << *account;
                Event::Account protoAccount;
                protoAccount.ParseFromString(*account);
                return make_optional(convertor::detail::decodeObject(protoAccount));
            } else {
                logger::debug("AccountRepository") << " data: (none)";
                return nullopt;
            }
        }

        bool add(
            std::string& publicKey,
            std::string& alias
        ) {
            logger::debug("AccountRepository") << "Add publicKey:" << publicKey << " alias:" << alias;
            object::Account ac(publicKey.c_str(),alias.c_str());
            auto protoAccount = convertor::detail::encodeObject(ac);
            std::string strAccount;
            protoAccount.SerializeToString(&strAccount);
            logger::debug("AccountRepository") << "Save key:" << hash::sha3_256_hex(publicKey) << " alias:" << alias;
            world_state_repository::add(hash::sha3_256_hex(publicKey), strAccount);
        }

    };
};