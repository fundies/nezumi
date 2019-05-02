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

#include <cstring>

#include <runtime/window.hpp>
#include <runtime/window/window.internal.hpp>

namespace nezumi
{
    void*   g_window_handle;
    int     g_window_width;
    int     g_window_height;
    int     g_window_x;
    int     g_window_y;
    bool    g_window_visible;
    bool    g_window_fullscreen;
    bool    g_window_focus;

    // Keyboard State
    bool    g_keyboard_current[vk_last];
    bool    g_keyboard_previous[vk_last];
    bool    g_keyboard_any_down;
    bool    g_keyboard_any_pressed;
    bool    g_keyboard_any_released;

    // Mouse State
    bool    g_mouse_current[mb_last];
    bool    g_mouse_previous[mb_last];
    bool    g_mouse_any_down;
    bool    g_mouse_any_pressed;
    bool    g_mouse_any_released;
    int     g_mouse_x;
    int     g_mouse_y;

    void window_update()
    {
        // Update Keyboard State
        std::memcpy(g_keyboard_previous, g_keyboard_current, vk_last * sizeof(bool));

        g_keyboard_any_pressed = false;
        g_keyboard_any_released = false;

        // Update Mouse State
        std::memcpy(g_mouse_previous, g_mouse_current, mb_last * sizeof(bool));

        g_mouse_any_pressed = false;
        g_mouse_any_released = false;
    }

    void* window_get_handle()
    {
        return g_window_handle;
    }

    int window_get_width()
    {
        return g_window_width;
    }

    int window_get_height()
    {
        return g_window_height;
    }

    int window_get_x()
    {
        return g_window_x;
    }

    int window_get_y()
    {
        return g_window_y;
    }

    bool window_get_visible()
    {
        return g_window_visible;
    }

    bool window_get_fullscreen()
    {
        return g_window_fullscreen;
    }

    bool window_get_focus()
    {
        return g_window_focus;
    }

    bool keyboard_check(int key)
    {
        if (key == vk_any) return g_keyboard_any_down;
        if (key < 0 || key >= vk_last) return false;

        return g_keyboard_current[key];
    }

    bool keyboard_check_pressed(int key)
    {
        if (key == vk_any) return g_keyboard_any_pressed;
        if (key < 0 || key >= vk_last) return false;

        return g_keyboard_current[key] && !g_keyboard_previous[key];
    }

    bool keyboard_check_released(int key)
    {
        if (key == vk_any) return g_keyboard_any_released;
        if (key < 0 || key >= vk_last) return false;

        return !g_keyboard_current[key] && g_keyboard_previous[key];
    }

    bool mouse_check(int button)
    {
        if (button == mb_any) return g_mouse_any_down;
        if (button < 0 || button >= mb_last) return false;

        return g_mouse_current[button];
    }

    bool mouse_check_pressed(int button)
    {
        if (button == mb_any) return g_mouse_any_pressed;
        if (button < 0 || button >= mb_last) return false;

        return g_mouse_current[button] && !g_mouse_previous[button];
    }

    bool mouse_check_released(int button)
    {
        if (button == mb_any) return g_mouse_any_released;
        if (button < 0 || button >= mb_last) return false;

        return !g_mouse_current[button] && g_mouse_previous[button];
    }
}