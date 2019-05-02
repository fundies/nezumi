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

#include <runtime/filesystem.hpp>

#include <windows.h>

namespace nezumi
{
    bool file_delete(const char* path)
    {
        return DeleteFileA(path);
    }

    bool file_exists(const char* path)
    {
        DWORD attr = GetFileAttributesA(path);
        return attr != INVALID_FILE_ATTRIBUTES &&
               (attr & FILE_ATTRIBUTE_DIRECTORY) == 0;
    }

    bool directory_create(const char* path)
    {
        return CreateDirectoryA(path, nullptr);
    }

    bool directory_delete(const char* path)
    {
        return RemoveDirectoryA(path);
    }

    bool directory_exists(const char* path)
    {
        DWORD attr = GetFileAttributesA(path);
        return attr != INVALID_FILE_ATTRIBUTES &&
               (attr & FILE_ATTRIBUTE_DIRECTORY);
    }
}