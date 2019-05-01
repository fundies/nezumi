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

#ifndef NEZUMI_RUNTIME_WINDOW_HPP
#define NEZUMI_RUNTIME_WINDOW_HPP

namespace nezumi
{
    /**
     * Defines the keys on the keyboard.
     */
    enum
    {
        // TODO: Implement "vk_any".

        /** Represents an undefined key. */
        vk_none = -1,

        /** The left arrow key. */
        vk_left,

        /** The right arrow key. */
        vk_right,

        /** The down arrow key. */
        vk_down,

        /** The up arrow key. */
        vk_up,

        /** The enter (or "return") key. */
        vk_enter,

        /** The escape key. */
        vk_escape,

        /** The number of defined keys. */
        vk_last,
    };

    /**
     * Defines the buttons on the mouse.
     */
    enum
    {
        // TODO: Implement "mb_any".

        /** Represents an undefined mouse button. */
        mb_none = -1,

        /** The left mouse button. */
        mb_left,

        /** The right mouse button. */
        mb_right,

        /** The middle mouse button. */
        mb_middle,

        /** The number of defined mouse buttons. */
        mb_last,
    };

    /** The X position of the mouse relative to the game window. */
    extern int g_mouse_x;

    /** The Y position of the mouse relative to the game window. */
    extern int g_mouse_y;

    /**
     * Centers the window on the primary display.
     */
    extern void window_center();

    /**
     * Sets the title of the window.
     * 
     * @param title The new title of the window.
     */
    extern void window_set_title(const char* title);

    /**
     * Sets the size of the window.
     * 
     * @param width The new width of the window.
     * @param height The new height of the window.
     */
    extern void window_set_size(int width, int height);

    /**
     * Sets the position of the window.
     * 
     * @param x The new X position of the window.
     * @param y The new Y position of the window.
     */
    extern void window_set_position(int x, int y);

    /**
     * Sets whether the window is visible.
     * 
     * @param visible True if the window should be visible; false otherwise.
     */
    extern void window_set_visible(bool visible);

    /**
     * Sets whether the window is fullscreen.
     * 
     * @param fullscreen True if the window should be fullscreen; false otherwise.
     */
    extern void window_set_fullscreen(bool fullscreen);

    /**
     * Gets the handle of the window.
     * 
     * @return The handle of the window.
     */
    extern void* window_get_handle();

    /**
     * Gets the width of the window.
     * 
     * @return The width of the window.
     */
    extern int window_get_width();

    /**
     * Gets the height of the window.
     * 
     * @return The height of the window.
     */
    extern int window_get_height();

    /**
     * Gets the X position of the window.
     * 
     * @return The X position of the window.
     */
    extern int window_get_x();

    /**
     * Gets the Y position of the window.
     * 
     * @return The Y position of the window.
     */
    extern int window_get_y();

    /**
     * Gets whether the window is visible.
     * 
     * @return True if the window is visible; false otherwise.
     */
    extern bool window_get_visible();

    /**
     * Gets whether the window is fullscreen.
     * 
     * @return True if the window is fullscreen; false otherwise.
     */
    extern bool window_get_fullscreen();

    /**
     * Gets whether the window is focused.
     * 
     * @return True if the window is focused; false otherwise.
     */
    extern bool window_get_focus();
    
    /**
     * Determines whether the specified key is currently down.
     * 
     * @param key The key to check.
     * 
     * @return True if the key is down; false otherwise.
     */
    extern bool keyboard_check(int key);

    /**
     * Determines whether the specified key was pressed within the last frame.
     * 
     * @param key The key to check.
     * 
     * @return True if the key was pressed; false otherwise.
     */
    extern bool keyboard_check_pressed(int key);

    /**
     * Determines whether the specified key was released within the last frame.
     * 
     * @param key The key to check.
     * 
     * @return True if the key was released; false otherwise.
     */
    extern bool keyboard_check_released(int key);

    /**
     * Determines whether the specified mouse button is currently down.
     * 
     * @param button The mouse button to check.
     * 
     * @return True if the mouse button is down; false otherwise.
     */
    extern bool mouse_check(int button);

    /**
     * Determines whether the specified mouse button was pressed within the
     * last frame.
     * 
     * @param button The mouse button to check.
     * 
     * @return True if the mouse button was pressed; false otherwise.
     */
    extern bool mouse_check_pressed(int button);

    /**
     * Determines whether the specified mouse button was released within the
     * last frame.
     * 
     * @param button The mouse button to check.
     * 
     * @return True if the mouse button was released; false otherwise.
     */
    extern bool mouse_check_released(int button);
}

#endif