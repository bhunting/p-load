#include "p-load.h"

enum PloaderTypeIds
{
    ID_NONE = 0,
    ID_P_STAR_25K50_BOOTLOADER,
    ID_PGM04A_BOOTLOADER,
    ID_PGM04A_APP,
#ifndef NDEBUG
    ID_SMC_18V25_APP,
    ID_SMC_18V25_BOOTLOADER,
#endif
};

const std::vector<PloaderAppType> ploaderAppTypes = {
    {
        /* id */ ID_PGM04A_APP,
        /* usbVendorId */ 0x1FFB,
        /* usbProductId */ 0x00B0,
        /* name */ "Pololu USB AVR Programmer v2",
        /* composite */ true,
        /* interfaceNumber */ 0,
    },
#ifndef NDEBUG
    {
        /* id */ ID_SMC_18V25_APP,
        /* usbVendorId */ 0x1FFB,
        /* usbProductId */ 0x009C,
        /* name */ "Pololu Simple High-Power Motor Controller 18v25",
        /* composite */ true,
        /* interfaceNumber */ 2,
    },
#endif
};

const std::vector<PloaderType> ploaderTypes = {
    {
        /* id */ ID_P_STAR_25K50_BOOTLOADER,
        /* usbVendorId */ 0x1FFB,
        /* usbProductId */ 0x0102,
        /* name */ "Pololu P-Star 25K50 Bootloader",
        /* appAddress */ 0x2000,
        /* appSize */ 0x6000,
        /* writeBlockSize */ 0x40,
        /* erasingFlashAffectsEeprom */ false,
        /* supportsFlashPlainWriting */ true,
        /* supportsFlashReading */ true,
        /* eepromAddress */ 0,
        /* eepromAddressHexFile */ 0xF00000,
        /* eepromSize */ 0x100,
        /* supportsEepromAccess */ true,
        /* deviceCode */ NULL,
        /* matchingAppTypes */ {},
    },
    {
        /* id */ ID_PGM04A_BOOTLOADER,
        /* usbVendorId */ 0x1FFB,
        /* usbProductId */ 0x00AF,
        /* name */ "Pololu USB AVR Programmer v2 Bootloader",
        /* appAddress */ 0x2000,
        /* appSize */ 0x6000,
        /* writeBlockSize */ 0x40,
        /* erasingFlashAffectsEeprom */ true,
        /* supportsFlashPlainWriting */ false,
        /* supportsFlashReading */ false,
        /* eepromAddress */ 0,
        /* eepromAddressHexFile */ 0xF00000,
        /* eepromSize */ 0x100,
        /* supportsEepromAccess */ true,
        /* deviceCode */ NULL,
        /* matchingAppTypes */ { ID_PGM04A_APP },
    },
#ifndef NDEBUG
    {
        /* id */ ID_SMC_18V25_BOOTLOADER,
        /* usbVendorId */ 0x1FFB,
        /* usbProductId */ 0x009B,
        /* name */ "Pololu Simple High-Power Motor Controller 18v25 Bootloader",
        /* appAddress */ 0x08002000,
        /* appSize */ 0xE000,
        /* writeBlockSize */ 0x40,
        /* erasingFlashAffectsEeprom */ true,
        /* supportsFlashPlainWriting */ false,
        /* supportsFlashReading */ false,
        /* eepromAddress */ 0,
        /* eepromAddressHexFile */ 0,
        /* eepromSize */ 0,
        /* supportsEepromAccess */ false,
        /* deviceCode */ NULL,
        /* matchingAppTypes */ { ID_SMC_18V25_APP },
    },
#endif
};

const std::vector<PloaderUserType> ploaderUserTypes = {
    {
        /* codeName */ "p-star",
        /* name */ "Pololu P-Star",
        /* memberIds */ { ID_P_STAR_25K50_BOOTLOADER },
    },
    {
        /* codeName */ "p-star-25k50",
        /* name */ "Pololu P-Star 25K50",
        /* memberIds */ { ID_P_STAR_25K50_BOOTLOADER },
    },
    {
        /* codeName */ "pgm04a",
        /* name */ "Pololu USB AVR Programmer v2",
        /* memberIds */ { ID_PGM04A_BOOTLOADER, ID_PGM04A_APP },
    },
#ifndef NDEBUG
    {
        /* codeName */ "smc",
        /* name */ "Pololu Simple Motor Controller",
        /* memberIds */ { ID_SMC_18V25_APP, ID_SMC_18V25_BOOTLOADER },
    },
#endif
};
