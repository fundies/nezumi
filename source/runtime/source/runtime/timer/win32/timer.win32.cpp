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

#include <windows.h>

namespace nezumi
{
    static double frequency;
    static double offset;

    bool timer_init()
    {
        LARGE_INTEGER result;

        // Get Frequency
        if (!QueryPerformanceFrequency(&result))
        {
            // TODO: Display Error Dialog
            return false;
        }

        frequency = static_cast<double>(result.QuadPart);

        // Get Offset
        if (!QueryPerformanceCounter(&result))
        {
            // TODO: Display Error Dialog
            return false;
        }

        offset = static_cast<double>(result.QuadPart);

        // Success
        return true;
    }

    double timer_get()
    {
        LARGE_INTEGER current;

        // Get Current Time
        QueryPerformanceCounter(&current);

        // Calculate Timer Value
        return (static_cast<double>(current.QuadPart) - offset) / frequency;
    }
}