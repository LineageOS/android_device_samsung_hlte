# Copyright (C) 2014-2016 The CyanogenMod Project
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

# inherit from common hlte
-include device/samsung/hlte-common/BoardConfigCommon.mk

TARGET_OTA_ASSERT_DEVICE := hlte,hltespr,hltexx

# Init
TARGET_INIT_VENDOR_LIB := libinit_msm8974
TARGET_LIBINIT_MSM8974_DEFINES_FILE := device/samsung/hlte/init/init_hlte.cpp

# Kernel
TARGET_KERNEL_CONFIG := lineage_hlte_bcm2079x_defconfig

# NFC
BOARD_NFC_HAL_SUFFIX := $(TARGET_BOARD_PLATFORM)

# Partitions
BOARD_BOOTIMAGE_PARTITION_SIZE := 11534336
BOARD_CACHEIMAGE_PARTITION_SIZE := 314572800
BOARD_RECOVERYIMAGE_PARTITION_SIZE := 13631488
BOARD_SYSTEMIMAGE_PARTITION_SIZE := 1572864000
BOARD_USERDATAIMAGE_PARTITION_SIZE := 28651290624

# Releasetools
TARGET_RELEASETOOLS_EXTENSIONS := device/samsung/hlte-common/releasetools

# inherit from the proprietary version
-include vendor/samsung/hlte/BoardConfigVendor.mk
