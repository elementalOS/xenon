#include <string.h>

int strncmp(const char* str1, const char* str2, size_t num) {
    while (num && *str1 && (*str1 == *str2)) {
        ++str1; ++str2; --num;
    }

    if (num == 0)
        return 0;

    return (*str1 - *str2);
}