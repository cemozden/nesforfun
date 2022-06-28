#ifndef NES_H
#define NES_H

#include <stdint.h>

typedef enum Mirroring {
    HORIZONTAL,
    VERTICAL
} Mirroring;

typedef struct NesHeader {
    uint32_t sign;
    uint8_t chr_rom_size;
    Mirroring mirroring;
} NesHeader;

#endif
