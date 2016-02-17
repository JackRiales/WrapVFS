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

#ifndef INODE_H
#define INODE_H

/*
    Wrap inode struct.
    Represents a file or directory.
*/
typedef struct {
    // The unique id of this inode and the file its associated with.
    uint32_t    id;

    // The number of hard links to the represented file.
    uint64_t    links;

    // Total size, in bytes. Will be 0 if its a directory.
    off_t       size;

    // Number of blocks allocated towards the data in this node.
    uint32_t    blocks;

    // Time of last access
    time_t      t_acc;

    // Time of last modification
    time_t      t_mod;

} wrap_inode;

#endif
