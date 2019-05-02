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

#include <cstdlib>
#include <cstdio>

#include <runtime/game.hpp>
#include <runtime/system.hpp>
#include <runtime/window.hpp>
#include <runtime/render.hpp>
#include <runtime/timer.hpp>
#include <runtime/math.hpp>
#include <runtime/color.hpp>

using namespace nezumi;

static void sample_init()
{
}

static void sample_exit()
{
}

static void sample_step()
{
    // Input Test
    if (keyboard_check_pressed(vk_any))
        std::puts("Key!");

    // Exit Game
    if (keyboard_check(vk_escape))
        game_end();
}

static void sample_draw()
{
    draw_clear(color_from_rgb(100, 149, 237), 1.0f);
}

int main(int argc, char** argv)
{
    temp_callbacks callbacks
    {
        sample_init,
        sample_exit,
        sample_step,
        sample_draw,
    };

    return game_main(argc, argv, callbacks);
}