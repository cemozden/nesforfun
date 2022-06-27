#include "file_utils.h"

#ifdef WIN32
# include<io.h>
#else
# include <unistd.h>
#endif


bool check_file_exist(const char* file_path) {
    if (access(file_path, F_OK) == 0) return true;
    else return false;
}
