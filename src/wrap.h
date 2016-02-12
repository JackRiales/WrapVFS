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

#ifndef WRAP_H
#define WRAP_H

#include <stdint.h>     // special int types
#include <stdbool.h>    // bool type

/*
    Wrap entity meta information.
    An entity is defined as either a file or a directory in the fs.\
        This struct will be used to write metafiles for entities.
*/
typedef struct {
    bool        is_dir;
    char*       path;
    char*       name;

    // Unsigned 64-bit integer used because super big files are pretty commmon.
    // If the entity is a directory, value should be 0.
    uint64_t    file_size;
} wrap_metainf;

/*
    Initialize and shutdown the VFS.
    Handles some allocation and deallocation necessities.
*/
void wrap_init();
void wrap_shutdown();

/*
    Make an empty file system in the file located at the given path.
*/
void wrap_mkfs(char *path, uint64_t alloc);

#endif // WRAP_H
