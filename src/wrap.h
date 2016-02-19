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

#include <sys/types.h>  // off_t
#include <stdio.h>      // FILE
#include <stdint.h>     // special int types
#include <stdbool.h>    // bool type
#include <time.h>       // time and date info

/*
    Wrap file system information.
    Created and serialized on mkfs; stored in the primary inode.
*/
typedef struct {
    // The path on the OS's file system to the file containing wrap
    char *path;

    // The file system's password. If not null, will be required to open.
    char *pwd;

    // The space on disk that the fs takes up.
    // Alternatively, the maximum amount of space the fs can store, unless dynamic is turned on.
    off_t stor_c;

    // The space actually being used in the fs.
    off_t stor_u;

    // The time and date when the file system was generated.
    time_t t_cre;

    // The time and date when the file system was last opened.
    time_t t_ope;

    // The time and date when the file system was last modified.
    time_t t_mod;
} wrap_fsinf;

// The real path to the .wrap file currently loaded and being used.
char *loaded_fs_path;

/*
    Initialize and shutdown the VFS.
    Handles some allocation and deallocation necessities.
*/
void wrap_init();
void wrap_shutdown();

/*
    Make an empty file system in the file located at the given path.
    Returns true if a .wrap file was able to form and allocate. False if not.
    fsname The name of the file system. Must end with the wrap file extension. If not, it will be applied.
    alloc How much space to allocate to the file system.
    altpath Where to put the file. If NULL, will be set to wherever the program is run.
*/
bool wrap_mkfs(char *fsname, uint64_t alloc, char *altpath);

/*
    Checks the integrity of the file system.
    Returns true if integrity is found intact, false if not.
*/
bool wrap_fsck();

/*
    Applies a password to the file system.
*/
bool wrap_fspwd(char *pass);

#endif
