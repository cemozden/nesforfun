cmake_minimum_required(VERSION 3.16)

project(nesforfun C)

add_executable(nesforfun src/main.c src/file_utils.h src/file_utils.c)

target_compile_features(nesforfun PRIVATE c_std_99)
