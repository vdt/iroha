#! /bin/sh
java -cp ../core/vendor/Aeron/aeron-samples/build/libs/samples.jar io.aeron.driver.MediaDriver &
../build/bin/iroha-main