#include <stdio.h>
#include "indent_manager.h"

void indent_print(int level) {
    for (int i = 0; i < level; i++) {
        printf("    ");
    }
}