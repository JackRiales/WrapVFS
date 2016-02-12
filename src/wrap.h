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
    Wrap file system information.
    Created and serialized on mkfs; stored in the primary inode.
*/
typedef struct {
    // The path on the OS's file system to the file containing wrap
    char *real_path;

    // The space on disk that the fs takes up.
    // Alternatively, the maximum amount of space the fs can store, unless dynamic is turned on.
    uint64_t storage_cap;

    // Is the storage capacity allowed to expand if needed?
    bool dynamic;
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
    char *data;

    // The meta information about the literal entity.
    wrap_metainf meta;

    // The parent to this inode.
    struct wrap_inode *parent;

    // An array of pointers, with an undefined length, to inodes serving as children.
    struct wrap_inode **children;
} wrap_inode_primary;

// Reference to the next free inode in the file system.
struct wrap_inode *NEXT_FREE_INODE;

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

/*
    Checks the integrity of the file system.
*/
void wrap_fsck();

#endif // WRAP_H
