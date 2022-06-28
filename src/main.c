#include <stdio.h>
#include "file_utils.h"
#include <stdlib.h>

#define MISSING_ROM_BIN_PATH_ERR_RETURN_CODE -1
#define ROM_FILE_DOES_NOT_EXIST_ERR_RETURN_CODE -2

void print_help();

int main(int argc, char** argv) {
    if (argc < 2) {
        print_help();
        return MISSING_ROM_BIN_PATH_ERR_RETURN_CODE;
    }

    const char* rom_path = argv[1];

    if (!check_file_exist(rom_path)) {
        printf("ROM file does not exist! Exiting...");
        return ROM_FILE_DOES_NOT_EXIST_ERR_RETURN_CODE;
    }

    printf("ROM Path: %s\n", rom_path);
    FILE* const file = fopen(rom_path, "rb");

    char* const rom_bin = get_rom_bin(file);

    if (rom_bin != NULL) {
        printf("First byte: %d", rom_bin[28]);
    }

    free(rom_bin);

    fclose(file);
    return 0;
}

void print_help() {
    printf("Usage: nesforfun ROM_FILE_PATH");
}
