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

    Configuration Value Guide

    Title               | Default   |   Usage
    -------------------------------------------------------------------------------------------------------------------------------
    WRAP_FILE_EXT       | ".wrap"   |   The file extension used when serializing the VFS.
    WRAP_META_FILE_EXT  | ".meta"   |   The file extension used by meta files, if applicable. See WRAP_USE_META below.
    WRAP_ROOT_SYMBOL    | "/"       |   The symbol to use for the root directory.
    WRAP_TEMP_ROOT_SYMB | "@/"      |   The symbol used to designate a temporary root directory.
    WRAP_PATH_SEPERATOR | "\\"      |   The symbol used to seperate paths.
    WRAP_INODE_PARENT   | ".."      |   The symbol to demarkate the parent of an inode.
    WRAP_INODE_THIS     | "."       |   The symbol an inode uses to demarkate itself.
    WRAP_BLOCK_HEADER   | "db:i%d"  |   The string used to introduce a block in the file system. '%d' is required as it representst the id.
    WRAP_BLOCK_HEADER_* | "|"       |   The symbol used to denote the beginning of the actual data in a block.
    WRAP_BLOCK_TERM     | ','       |   Symbol used to terminate data blocks in the file system.
    WRAP_BLOCK_NULL     | '~'       |   A char used to represent that there is no real data on an index.
    WRAP_USE_META       | true      |   Should wrap encode file metadata in meta files (true), or embed them onto the headers of files (false)?
    WRAP_META_HIDDEN    | true      |   Should wrap "hide" metafiles by appending the hidden symbol to them on creation?
    WRAP_PRIME_ID       | 0         |   The id given to the prime data block, containing the file system info.
    WRAP_ROOT_ID        | 1         |   The id given to the root inode / data block in the file system.
    WRAP_FS_MIN_ALLOC   | 2048 (B)  |   The minimum amount of bytes the file system must have allocated during mkfs.
    WRAP_EXIT_FAILURE   | -1        |   Program exit code used to indicate a general error has caused the fs to quit.
    WRAP_EXIT_SUCCESS   | 0         |   Program exit code used to indicate the user has caused the fs to quit. Best case.
    WRAP_BLOCK_SIZE     | 512       |   The size of the datablocks that can be allocated for real containment. Defined in preproc for array use.
*/

#ifndef WRAP_CONFIG_H
#define WRAP_CONFIG_H

/*const char *WRAP_FILE_EXT           = ".wrap";
const char *WRAP_META_FILE_EXT      = ".meta";
const char *WRAP_ROOT_SYMBOL        = "/";
const char *WRAP_TEMP_ROOT_SYMBOL   = "@/";
const char *WRAP_PATH_SEPERATOR     = "/";
const char *WRAP_INODE_PARENT       = "..";
const char *WRAP_INODE_THIS         = ".";
const char *WRAP_BLOCK_HEADER       = "db:i%d";
const char *WRAP_BLOCK_HEADER_TERM  = "|";
const char  WRAP_BLOCK_TERM         = ',';
const int   WRAP_USE_META           = 1;
const int   WRAP_META_HIDDEN        = 1;
const int   WRAP_PRIME_ID           = 0;
const int   WRAP_ROOT_ID            = 1;
const int   WRAP_FS_MIN_ALLOC       = 2048;
const int   WRAP_EXIT_FAILURE       = -1;
const int   WRAP_EXIT_SUCCESS       = 0;*/
#define WRAP_FILE_EXT               ".wrap"
#define WRAP_META_FILE_EXT          ".meta"
#define WRAP_ROOT_SYMBOL            "/"
#define WRAP_TEMP_ROOT_SYMBOL       "@/"
#define WRAP_PATH_SEPERATOR         "/"
#define WRAP_INODE_PARENT           ".."
#define WRAP_INODE_THIS             "."
#define WRAP_BLOCK_HEADER           "db:i%d"
#define WRAP_BLOCK_HEADER_TERM      "|"
#define WRAP_BLOCK_TERM             '\n'
#define WRAP_BLOCK_NULL             '~'
#define WRAP_BLOCK_SIZE             512
#define WRAP_USE_META               1
#define WRAP_META_HIDDEN            1
#define WRAP_PRIME_ID               0
#define WRAP_ROOT_ID                1
#define WRAP_FS_MIN_ALLOC           2048
#define WRAP_EXIT_FAILURE           -1
#define WRAP_EXIT_SUCCESS           0

#endif
