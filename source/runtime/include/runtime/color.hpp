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

#ifndef NEZUMI_RUNTIME_COLOR_HPP
#define NEZUMI_RUNTIME_COLOR_HPP

#include <cstdint>

namespace nezumi
{
    /** Defines a packed RGB color value. */
    using color_t = std::uint32_t;

    /**
     * Defines the color constants.
     */
    enum
    {
        /** A black color value. */
        c_black = 0x000000,

        /** A white color value. */
        c_white = 0xFFFFFF,

        /** A red color value. */
        c_red = 0xFF0000,

        /** A green color value. */
        c_green = 0x00FF00,

        /** A blue color value. */
        c_blue = 0x0000FF,

        /** A yellow color value. */
        c_yellow = 0xFFFF00,
    };

    /**
     * Constructs a packed RGB color value.
     * 
     * @param r The value of the red component between 0 and 255.
     * @param g The value of the green component between 0 and 255.
     * @param b The value of the blue component between 0 and 255.
     * 
     * @return The new color value.
     */
    static inline color_t color_from_rgb(int r, int g, int b)
    {
        return ((r & 0xFF) << 16) | ((g & 0xFF) << 8) | (b & 0xFF);
    }

    /**
     * Gets the red component of the specified color value.
     * 
     * @param color The color value to get the red component of.
     * 
     * @return The red component between 0 and 255.
     */
    static inline int color_get_red(color_t color)
    {
        return (color >> 16) & 0xFF;
    }

    /**
     * Gets the green component of the specified color value.
     * 
     * @param color The color value to get the green component of.
     * 
     * @return The green component between 0 and 255.
     */
    static inline int color_get_green(color_t color)
    {
        return (color >> 8) & 0xFF;
    }

    /**
     * Gets the blue component of the specified color value.
     * 
     * @param color The color value to get the blue component of.
     * 
     * @return The blue component between 0 and 255.
     */
    static inline int color_get_blue(color_t color)
    {
        return color & 0xFF;
    }
}

#endif