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

#ifndef USER_H
#define USER_H

/*
    Creates a directory (node) at the given path, if it exists.
*/
bool wrap_mkdir(char *path, bool force);

/*
    Removes a directory (node) at the given path, if it exists.
*/
bool wrap_rmdir(char *path);

/*
    Creates an empty file of the given name at the given directory.
    If path is NULL, the default will be '.'
*/
bool wrap_touch(char *name, char *path);

/*
    Creates a directory (node) at the given path, if it exists.
*/
bool wrap_mv(char *node, char *path);

/*
    Copies a node to a new location (default '.')
*/
bool wrap_cp(char *node, char *path);

/*
    Displays all the files and directories in the given path (default '.')

    Arg         | Code      | Description
    Long-form   | -l        | Displays all information about each node.
*/
char** wrap_ls(char *path, char *args[]);

/*
    Marks the current inode ('.') as the current directory, if it exists.
*/
bool wrap_cd(char *path);

/*
    Gives information about the given inode.
*/
bool wrap_stat(char *node);

/*
    Secure the given node with a password.
    Passwords will be hashed and secured in the node information.
    If pass is null, will render the node insecure.
*/
bool wrap_pwd(char *node, char *pass);

#endif // USER_H
