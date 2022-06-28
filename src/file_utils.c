#include "file_utils.h"
#include <stdio.h>
#include <stdlib.h>

#ifdef WIN32
#include<io.h>
#else
#include <unistd.h>
#endif


const bool check_file_exist(const char* file_path) {
    if (access(file_path, F_OK) == 0) return true;
    else return false;
}

char* const get_rom_bin(FILE* file) {
    const FILE_SIZE rom_size = get_file_size(file);
    //TODO: Add file size check here

    char* const rom_bin = malloc(sizeof(char) * rom_size);

    const int num_of_bytes_read = fread(rom_bin, sizeof(char), rom_size, file);

    if (num_of_bytes_read != 0) return rom_bin;
    else return NULL;
}


const FILE_SIZE get_file_size(FILE *file) {
    const long current_file_pos = ftell(file);
    fseek(file, 0L, SEEK_END);
    const FILE_SIZE file_size = ftell(file);

    fseek(file, 0L, current_file_pos);

    return file_size;
}

