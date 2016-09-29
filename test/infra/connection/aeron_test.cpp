#include "../../core/crypto/hash.hpp"

#include <gtest/gtest.h>
#include <string>
#include <iostream>

TEST(Hash, sha3_256_empty_text) {
    std::string res = "a7ffc6f8bf1ed76651c14756a061d662f580ff4de43b49fa82d80a4b80f8434a";
    ASSERT_STREQ(
        hash::sha3_256_hex("").c_str(),
        res.c_str()
    );
}
