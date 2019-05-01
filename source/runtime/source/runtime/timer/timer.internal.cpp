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

#include <runtime/timer.hpp>
#include <runtime/timer/timer.internal.hpp>

namespace nezumi
{
    int     g_fps;
    double  g_delta_time;

    // The timer value for the previous frame.
    static double previous;

    // The elapsed number of seconds since the last FPS update.
    static double fps_timer;

    // The elapsed number of frames since the last FPS update.
    static int fps_counter;

    void timer_update()
    {
        // Get Current
        double current = timer_get();

        // Update Delta
        g_delta_time = current - previous;

        // Update Previous
        previous = current;

        // Update FPS
        fps_timer += g_delta_time;
      ++fps_counter;

        if (fps_timer >= 1.0)
        {
            g_fps = fps_counter;

            // Reset Counter
            fps_timer = 0.0;
            fps_counter = 0;
        }
    }
}