SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

SET(SMART_CONTRACT_PATH ${PROJECT_SOURCE_DIR}/smart_contract)

include_directories(
  ${SMART_CONTRACT_PATH}
  /usr/lib/jvm/java-1.8.0-openjdk-amd64/include
  /usr/lib/jvm/java-1.8.0-openjdk-amd64/include/linux
)

link_directories(
  ${LIBRARY_OUTPUT_PATH}
  /usr/lib/
)

ADD_LIBRARY(AccountRepository SHARED repository/account_repository_jni.cpp)
target_link_libraries(AccountRepository
  domain_repository
  convertor
)

ADD_LIBRARY(AssetRepository SHARED repository/asset_repository_jni.cpp)
target_link_libraries(AssetRepository
  domain_repository
  convertor
)