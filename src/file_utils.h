#ifndef FILE_UTILS_H

#define FILE_UTILS_H
#include <stdbool.h>
#include <stdio.h>

typedef unsigned long FILE_SIZE;

const bool check_file_exist(const char* file_path);
const FILE_SIZE get_file_size(FILE* file);
char* const get_rom_bin(FILE* file);

#endif
