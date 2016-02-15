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

#ifndef UTIL_H
#define UTIL_H

#include <stdbool.h>

// Adds one string to another, and returns the result.
char* concat_string(const char *str1, const char *str2);

// Displays a yes or no prompt, and returns true on Y and false on N
bool confirm(char *cmessage, bool def);

#endif // UTIL_H
