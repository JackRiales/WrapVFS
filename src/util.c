/*
    ===============================================================
    Wrap -- Single File Virtual File System
    Copyright (C) 2016  Jack Riales

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
    ===============================================================
*/

#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concat_string(const char *str1, const char *str2) {
    char *concat = (char *) malloc(strlen(str1) + strlen(str2) + 1);
    strcpy(concat, str1);
    strcat(concat, str2);
    printf("Concatenated %s with %s and formed %s.\n", str1, str2, concat);
    return concat;
}

bool confirm(char str[], char *cmessage, bool def) {
    if (cmessage == NULL) {
        cmessage = "Confirm [Y/N]: ";
    }
    printf("%s", cmessage);
    scanf("%s", str);
    if (strcmp(str, "Y") == 0 || strcmp(str, "y") == 0) {
        return true;
    } else if (strcmp(str, "N") == 0 || strcmp(str, "n") == 0) {
        return false;
    } else {
        return def;
    }
}
