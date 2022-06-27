#include <stdio.h>
#include "file_utils.h"

void print_help();

int main(int argc, char** argv) {
    if (argc < 2) {
        print_help();
        return -1;
    }

    const char* rom_path = argv[1];

    if (!check_file_exist(rom_path)) {
        printf("ROM file does not exist! Exiting...");
        return -2;
    }

    printf("ROM Path: %s\n", rom_path);

    return 0;
}

void print_help() {

    printf("Usage: nesforfun ROM_FILE_PATH");

}
