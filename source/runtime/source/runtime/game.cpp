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

#include <runtime/game.hpp>
#include <runtime/window.hpp>
#include <runtime/render.hpp>
#include <runtime/timer.hpp>

#include <runtime/window/window.internal.hpp>
#include <runtime/render/render.internal.hpp>
#include <runtime/timer/timer.internal.hpp>

namespace nezumi
{
    // Whether the game has been flagged to exit.
    static bool exiting;

    // Whether the game has been painted at least once.
    static bool painted;

    int game_main(int argc, char** argv, const temp_callbacks& callbacks)
    {
        // Initialize Window
        if (!window_init("Nezumi Game", 1280, 720))
            return EXIT_FAILURE;

        // Initialize Render
        if (!render_init())
            return EXIT_FAILURE;

        // Initialize Audio
        // ...

        // Initialize Input
        // ...

        // Initialize Timer
        if (!timer_init())
            return EXIT_FAILURE;

        // Initialize Game
        callbacks.init();

        // Game Loop
        while (!exiting)
        {
            // Window Input
            window_update();

            // Window Events
            if (!window_events())
                break;

            // Update Timer
            timer_update();

            // Update Game
            callbacks.step();

            // Render Game
            callbacks.draw();

            // Swap Buffers
            render_swap_buffers();

            // Frame Painted
            if (!painted)
            {
                painted = true;

                // Show the window only after the first frame has been fully
                // rendered so the user doesn't see an unpainted window while
                // the game starts up.
                window_set_visible(true);
            }
        }

        // Shutdown Game
        callbacks.exit();

        // Success
        return EXIT_SUCCESS;
    }

    void game_end()
    {
        exiting = true;
    }
}