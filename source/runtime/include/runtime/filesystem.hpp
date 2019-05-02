/**
 * Copyright (c) 2019 Noah Johnson
 * 
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 * 
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 * 
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 */

#ifndef NEZUMI_RUNTIME_FILESYSTEM_HPP
#define NEZUMI_RUNTIME_FILESYSTEM_HPP

namespace nezumi
{
    /**
     * Deletes the file at the specified path.
     * 
     * @param path The path of the file to delete.
     * 
     * @return True on success; false if an error occurred.
     */
    extern bool file_delete(const char* path);

    /**
     * Determines whether a file exists at the specified path.
     * 
     * @param path The path of the file to check.
     * 
     * @return True if the file exists; false otherwise.
     */
    extern bool file_exists(const char* path);

    /**
     * Creates a directory at the specified path.
     * 
     * This function will attempt to create a directory at the specified path,
     * returning false if a new directory could not be created. It should be
     * noted that this function will not attempt to create any non-existent
     * intermediate directories specified in the path, and will simply return
     * false instead.
     * 
     * @param path The path of the directory to create.
     * 
     * @return True on success; false if an error occurred.
     */
    extern bool directory_create(const char* path);

    /**
     * Deletes the directory at the specified path if it is empty.
     * 
     * @param path The path of the directory to delete.
     * 
     * @return True on success; false if an error occurred.
     */
    extern bool directory_delete(const char* path);

    /**
     * Determines whether a directory exists at the specified path.
     * 
     * @param path The path of the directory to check.
     * 
     * @return True if the directory exists; false otherwise.
     */
    extern bool directory_exists(const char* path);
}

#endif