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

#include "wrap.h"
#include "inode.h"
#include "util.h"
#include "config.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*===============================================================*/
int main(int argc, char *argv[]) {
    //#ifdef __DEBUG
    if (!wrap_mkfs("Testing", 1024*1024, NULL)) {
        return WRAP_EXIT_FAILURE;
    }
    return WRAP_EXIT_SUCCESS;
    //#else
    //if (argc > 1) {

    //} else {
    //    return 1;
    //}
    //#endif
}

/*===============================================================*/
void wrap_init() {

}

/*===============================================================*/
void wrap_shutdown() {

}

/*===============================================================*/
bool wrap_mkfs(char *fsname, uint64_t alloc, char *altpath) {
    // Check and ensure that there's enough data space to contain at least the basic system
    if (alloc < sizeof(wrap_fsinf) + sizeof(wrap_inode) * 2) {
        printf("ERROR: Allocated size is not enough to hold basic system.");
        return false;
    }

    // Check if fsname contains .wrap. If not, it needs to be applied.
    char *fsname_full;
    if (strstr(fsname, WRAP_FILE_EXT) != NULL) {
        fsname_full = fsname;
    } else {
        fsname_full = concat_string(fsname, WRAP_FILE_EXT);
    }

    // Form a string of the path we want
    char *fullpath;
    if (altpath == NULL) {
        fullpath = concat_string("./", fsname_full);
    } else {
        fullpath = concat_string(altpath, fsname_full);
    }

    // Check if the fullpath already exists.
    if (access(fullpath, F_OK) != -1) {
        if (!confirm("WARNING: File already exists. Are you sure you want to make a new file system here? [y/N]: ", false)) {
            return false;
        }
    }

    // Attempt to create the file for writing.
    FILE *f = fopen(fullpath, "wb");

    // Exception check
    if (f == NULL) {
        // Error here
        return false;
    }

    // Preallocate space to it
    ftruncate(fileno(f), alloc);

    // Mark the fs now as loaded
    loaded_fs_path = fullpath;

    // Generate file system info struct
    wrap_fsinf fsysinfo;
    fsysinfo.path = fullpath;
    fsysinfo.stor_c = alloc;
    fsysinfo.stor_u = 0;
    fsysinfo.pwd = NULL;
    time_t rawtime;
    time (&rawtime);
    fsysinfo.t_cre = rawtime;
    fsysinfo.t_ope = rawtime;
    fsysinfo.t_mod = rawtime;

    // Close the file
    fclose(f);

    // Free up the strings we made
    free(fsname_full);
    fsname_full = NULL;
    free(fullpath);
    fullpath = NULL;

    return true;
}
