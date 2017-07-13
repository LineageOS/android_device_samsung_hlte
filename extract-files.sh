#!/bin/bash
#
# Copyright (C) 2016 The CyanogenMod Project
# Copyright (C) 2017 The LineageOS Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

set -e

if [ -z "$VARIANT" ] ; then
    echo "*** ERROR: This is a multi-blob variant device. ***"
    echo "  Please ensure you set VARIANT environment variable."
    echo "  HINT: VARIANT value should match with a"
    echo "  device-proprietary-files-\${VARIANT}.txt file."
    exit 1
else
    if [ ! -f "device-proprietary-files-${VARIANT}.txt" ] ; then
        echo "*** ERROR: device-proprietary-files-${VARIANT}.txt not found. ***"
        echo "  Please check whether VARIANT is set improperly or if a file is missing."
        exit 1
    fi
fi

export DEVICE=hlte
export DEVICE_COMMON=hlte-common
export VENDOR=samsung

./../$DEVICE_COMMON/extract-files.sh $@
