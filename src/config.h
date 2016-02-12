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
    WRAP_USE_META       | true      |   Should wrap encode file metadata in meta files, or embed them onto the headers of files?
    WRAP_META_HIDDEN    | true      |   Should wrap "hide" metafiles by appending the hidden symbol to them on creation?
*/

#ifndef WRAP_CONFIG_H
#define WRAP_CONFIG_H

const char *WRAP_FILE_EXT       = ".wrap";
const char *WRAP_META_FILE_EXT  = ".meta";
const char *WRAP_ROOT_SYMBOL    = "/";
const char *WRAP_PATH_SEPERATOR = "\\";
const int   WRAP_USE_META       = 1;
const int   WRAP_META_HIDDEN    = 1;

#endif // WRAP_CONFIG_H
