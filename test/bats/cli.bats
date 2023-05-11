#!/usr/bin/env bats

# This is run relative to the root
# We also assume the binaries are built
BIN_DIR=./bin
TEST_DIR=./test/bats
SLEEP_TIME=10

@test "submit test" {
  flux start ${TEST_DIR}/test_submit.sh
}
