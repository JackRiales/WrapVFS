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
#include <time.h>       // time and date info

/*
    Wrap file system information.
    Created and serialized on mkfs; stored in the primary inode.
*/
typedef struct {
    // The path on the OS's file system to the file containing wrap
    char *real_path;

    // The space on disk that the fs takes up.
    // Alternatively, the maximum amount of space the fs can store, unless dynamic is turned on.
    uint64_t storage_cap;

    // The space actually being used in the fs.
    uint64_t used_storage;

    // The file system's password. If not null, will be required to open.
    char *pwd;

    // The time and date when the file system was generated.
    struct tm * time_on_create;
} wrap_fsinf;

/*
    Wrap entity meta information.
    An entity is defined as either a file or a directory in the fs.\
        This struct will be used to write metafiles for entities.
*/
typedef struct {
    bool        is_dir;
    char*       path;
    char*       name;

    // The space allocated to this inode.
    // Unsigned 64-bit integer used because files > 2G are pretty commmon.
    // If the entity is a directory, value should be 0.
    uint64_t    alloc;
} wrap_metainf;

/*
    Wrap inode struct.
    Represents a file or directory.
*/
struct wrap_inode {
    // The unique identifier of the inode
    int uid;

    // Is this inode the root? Should never be true if this inode is a file.
    bool is_root;

    // The actual data contained within this inode.
    // Should be NULL if this inode is a directory.
    void *data;

    // The meta information about the literal entity.
    wrap_metainf meta;

    // The node's security password. If not null, will require authentication in order to use.
    char *pwd;

    // The parent to this inode.
    struct wrap_inode *parent;

    // An array of pointers, with an undefined length, to inodes serving as children.
    struct wrap_inode **children;
};
typedef struct wrap_inode wrap_inode;

// The primary inode will contain the file system info
wrap_inode primary_inode;

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

*/
bool wrap_write(wrap_inode *inode);

/*
    Applies a password to the file system.
*/
bool wrap_fspwd(char *pass);

#endif // WRAP_H
