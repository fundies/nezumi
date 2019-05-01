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

#include <runtime/window.hpp>
#include <runtime/window/window.internal.hpp>

namespace nezumi
{
    bool window_init(const char* title, int width, int height)
    {
        return true;
    }

    bool window_events()
    {
        return true;
    }

    void window_center()
    {
    }

    void window_set_title(const char* title)
    {
    }

    void window_set_size(int width, int height)
    {
    }

    void window_set_position(int x, int y)
    {
    }

    void window_set_visible(bool visible)
    {
    }

    void window_set_fullscreen(bool fullscreen)
    {
    }
}