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

#ifndef NEZUMI_RUNTIME_WINDOW_INTERNAL_HPP
#define NEZUMI_RUNTIME_WINDOW_INTERNAL_HPP

namespace nezumi
{
    /** The handle of the window. */
    extern void* g_window_handle;

    /** The width of the window. */
    extern int g_window_width;

    /** The height of the window. */
    extern int g_window_height;

    /** The X position of the window. */
    extern int g_window_x;

    /** The Y position of the window. */
    extern int g_window_y;

    /** Whether the window is visible. */
    extern bool g_window_visible;

    /** Whether the window is fullscreen. */
    extern bool g_window_fullscreen;

    /** Whether the window is focused. */
    extern bool g_window_focus;

    /** The keyboard state for the current frame. */
    extern bool g_keyboard_current[];

    /** The keyboard state for the previous frame. */
    extern bool g_keyboard_previous[];

    /** Whether any key is currently down. */
    extern bool g_keyboard_any_down;

    /** Whether any key was pressed within the last frame. */
    extern bool g_keyboard_any_pressed;

    /** Whether any key was released within the last frame. */
    extern bool g_keyboard_any_released;

    /** The mouse state for the current frame. */
    extern bool g_mouse_current[];

    /** The mouse state for the previous frame. */
    extern bool g_mouse_previous[];

    /** Whether any mouse button is currently down. */
    extern bool g_mouse_any_down;

    /** Whether any mouse button was pressed within the last frame. */
    extern bool g_mouse_any_pressed;

    /** Whether any mouse button was released within the last frame. */
    extern bool g_mouse_any_released;

    /**
     * Initializes the window module.
     * 
     * @param title The title of the window.
     * @param width The width of the window.
     * @param height The height of the window.
     * 
     * @return True on success; false if an error occurred.
     */
    extern bool window_init(const char* title, int width, int height);

    /**
     * Handles incoming window events.
     * 
     * @return True if the window is still open; false otherwise.
     */
    extern bool window_events();

    /**
     * Updates per-frame input states for the window.
     */
    extern void window_update();
}

#endif