#!/usr/bin/env bash

SNPE_LIB=build_android_aarch64/aarch64-release/test_demo

adb push $SNPE_LIB /data/local/tmp/
bin_path="/data/local/tmp/test_demo"
adb shell "chmod +x ${bin_path}/demo_test"
adb shell "cd ${bin_path} \
          && export LD_LIBRARY_PATH=${bin_path}:${LD_LIBRARY_PATH} \
          && ./demo_test "
adb pull /data/local/tmp/test_demo/file.txt ~/Desktop
