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

#include "block.h"

/*===============================================================*/
void wrap_dbinit(wrap_datablock *db) {
    /*for (int i = 0; i < WRAP_BLOCK_SIZE; i++)
        db->data[i] = WRAP_BLOCK_NULL;*/

    // Write the terminating string to the end of the data array
    db->data[WRAP_BLOCK_SIZE - 1] = WRAP_BLOCK_TERM;

    // Flag the block as initialized
    db->fl_init = true;
}

/*===============================================================*/
bool wrap_dbwrite(wrap_datablock *db, FILE *f) {
    if (db == NULL || f == NULL) {
        return false;
    }

    if (!db->fl_init)
        wrap_dbinit(db);

    fprintf(f, WRAP_BLOCK_HEADER, db->id);
    fprintf(f, WRAP_BLOCK_HEADER_TERM);
    fprintf(f, "%s", db->data);

    return true;
}
