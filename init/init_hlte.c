/*
   Copyright (c) 2013, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

#include "init_msm.h"

void init_msm_properties(unsigned long msm_id, unsigned long msm_ver, char *board_type)
{
    char platform[PROP_VALUE_MAX];
    char bootloader[PROP_VALUE_MAX];
    char device[PROP_VALUE_MAX];
    char devicename[PROP_VALUE_MAX];
    int rc;

    UNUSED(msm_id);
    UNUSED(msm_ver);
    UNUSED(board_type);

    rc = property_get("ro.board.platform", platform);
    if (!rc || !ISMATCH(platform, ANDROID_TARGET))
        return;

    property_get("ro.bootloader", bootloader);

    if (strstr(bootloader, "N900W8")) {
        /* hltecan */
        gsm_properties();
        property_set("ro.build.fingerprint", "samsung/hltecan/hlte:4.4.2/KOT49H/N900W8VLUCND5:user/release-keys");
        property_set("ro.build.description", "hltecan-user 4.4.2 KOT49H N900W8VLUCND5 release-keys");
        property_set("ro.product.model", "SM-N900W8");
        property_set("ro.product.device", "hltecan");
    } else if (strstr(bootloader, "N900P")) {
        /* hltespr */
        cdma_properties("1");
        property_set("ro.build.fingerprint", "samsung/hltespr/hltespr:4.4.2/KOT49H/N900PVPUCNAB:user/release-keys");
        property_set("ro.build.description", "hltespr-user 4.4.2 KOT49H N900PVPUCNAB release-keys");
        property_set("ro.product.model", "SM-N900P");
        property_set("ro.product.device", "hltespr");
    } else if (strstr(bootloader, "N900T")) {
        /* hltetmo */
        gsm_properties();
        property_set("ro.build.fingerprint", "samsung/hltetmo/hltetmo:4.4.2/KOT49H/N900TUVUCNB4:user/release-keys");
        property_set("ro.build.description", "hltetmo-user 4.4.2 KOT49H N900TUVUCNB4 release-keys");
        property_set("ro.product.model", "SM-N900T");
        property_set("ro.product.device", "hltetmo");
    } else if (strstr(bootloader, "N900V")) {
        /* hltevzw */
        cdma_properties("0");
        property_set("ro.build.fingerprint", "samsung/hltevzw/hltevzw:4.4.2/KOT49H/N900VVRUCNC2:user/release-keys");
        property_set("ro.build.description", "hltevzw-user 4.4.2 KOT49H N900VVRUCNC2 release-keys");
        property_set("ro.product.model", "SM-N900V");
        property_set("ro.product.device", "hltevzw");
        property_set("ro.cdma.home.operator.alpha", "Verizon");
        property_set("ro.cdma.home.operator.numeric", "311480");
    } else if (strstr(bootloader, "N900R4")) {
        /* hlteusc */
        cdma_properties("0");
        property_set("ro.build.fingerprint", "samsung/hlteusc/hlteusc:4.4.2/KOT49H/N900R4TYUCNAB:user/release-keys");
        property_set("ro.build.description", "hlteusc-user 4.4.2 KOT49H N900R4TYUCNAB release-keys");
        property_set("ro.product.model", "SM-N900R4");
        property_set("ro.product.device", "hlteusc");
        property_set("ro.cdma.home.operator.alpha", "U.S.Cellular");
        property_set("ro.cdma.home.operator.numeric", "311580");
    } else {
        /* hltexx */
        gsm_properties();
        property_set("ro.build.fingerprint", "samsung/hltexx/hlte:4.4.2/KOT49H/N9005XXUENC2:user/release-keys");
        property_set("ro.build.description", "hltexx-user 4.4.2 KOT49H N9005XXUENC2 release-keys");
        property_set("ro.product.model", "SM-N9005");
        property_set("ro.product.device", "hltexx");
    }
    property_get("ro.product.device", device);
    strlcpy(devicename, device, sizeof(devicename));
    ERROR("Found bootloader id %s setting build properties for %s device\n", bootloader, devicename);
}

void gsm_properties()
{
    property_set("ro.telephony.default_network", "9");
    property_set("ro.telephony.ril.v3", "newDialCode");
    property_set("telephony.lteOnGsmDevice", "1");
}

void cdma_properties(char cdma_sub[])
{
    property_set("ro.telephony.default_cdma_sub", cdma_sub); // 0: RUIM/SIM  1: NV
    property_set("ro.telephony.default_network", "10");
    property_set("ro.telephony.ril.v3", "newDriverCallU,newDialCode");
    property_set("telephony.lteOnCdmaDevice", "1");
}
