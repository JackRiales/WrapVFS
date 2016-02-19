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

#ifndef BLOCK_H
#define BLOCK_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "config.h"

typedef struct {
    bool fl_init;
    uint32_t id;
    unsigned char data [WRAP_BLOCK_SIZE];
} wrap_datablock;

void wrap_dbinit(wrap_datablock *db);
bool wrap_dbwrite(wrap_datablock *db, FILE *f);

#endif
