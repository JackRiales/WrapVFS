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
    WRAP_USE_META       | true      |   Should wrap encode file metadata in meta files (true), or embed them onto the headers of files (false)?
    WRAP_META_HIDDEN    | true      |   Should wrap "hide" metafiles by appending the hidden symbol to them on creation?
    WRAP_BLOCK_SIZE     | 512       |   The size of the datablocks that can be allocated for real containment.
    WRAP_EXIT_FAILURE   | -1        |   Program exit code used to indicate a general error has caused the fs to quit.
    WRAP_EXIT_SUCCESS   | 0         |   Program exit code used to indicate the user has caused the fs to quit. Best case.
*/

#ifndef WRAP_CONFIG_H
#define WRAP_CONFIG_H

const char *WRAP_FILE_EXT           = ".wrap";
const char *WRAP_META_FILE_EXT      = ".meta";
const char *WRAP_ROOT_SYMBOL        = "/";
const char *WRAP_TEMP_ROOT_SYMBOL   = "@/";
const char *WRAP_PATH_SEPERATOR     = "/";
const char *WRAP_INODE_PARENT       = "..";
const char *WRAP_INODE_THIS         = ".";
const int   WRAP_USE_META           = 1;
const int   WRAP_META_HIDDEN        = 1;
const int   WRAP_BLOCK_SIZE         = 512;
const int   WRAP_EXIT_FAILURE       = -1;
const int   WRAP_EXIT_SUCCESS       = 0;

#endif // WRAP_CONFIG_H
