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

#ifndef NEZUMI_RUNTIME_MATH_HPP
#define NEZUMI_RUNTIME_MATH_HPP

#include <cmath>

namespace nezumi
{
    /** The value of pi. */
    static constexpr double k_pi = 3.14159265358979323846;

    /** Degrees-to-radians conversion constant. */
    static constexpr double k_degtorad = k_pi / 180.0;

    /** Radians-to-degrees conversion constant. */
    static constexpr double k_radtodeg = 180.0 / k_pi;

    /**
     * Gets the cosine of the specified angle.
     * 
     * @param angle The angle to get the cosine of.
     * 
     * @return The cosine of the angle.
     */
    static inline double cos(double angle)
    {
        return std::cos(angle);
    }

    /**
     * Gets the sine of the specified angle.
     * 
     * @param angle The angle to get the sine of.
     * 
     * @return The sine of the angle.
     */
    static inline double sin(double angle)
    {
        return std::sin(angle);
    }

    /**
     * Gets the tangent of the specified angle.
     * 
     * @param angle The angle to get the tangent of.
     * 
     * @return The tangent of the angle.
     */
    static inline double tan(double angle)
    {
        return std::tan(angle);
    }

    /**
     * Gets the cosine of the specified degrees-based angle.
     * 
     * @param angle The angle (in degrees) to get the cosine of.
     * 
     * @return The cosine of the specified angle.
     */
    static inline double dcos(double angle)
    {
        return std::cos(angle * k_degtorad);
    }

    /**
     * Gets the sine of the specified degrees-based angle.
     * 
     * @param angle The angle (in degrees) to get the sine of.
     * 
     * @return The sine of the specified angle.
     */
    static inline double dsin(double angle)
    {
        return std::sin(angle * k_degtorad);
    }

    /**
     * Gets the tangent of the specified degrees-based angle.
     * 
     * @param angle The angle (in degrees) to get the tangent of.
     * 
     * @return The tangent of the specified angle.
     */
    static inline double dtan(double angle)
    {
        return std::tan(angle * k_degtorad);
    }

    /**
     * Converts the specified angle from degrees to radians.
     * 
     * @param angle The angle (in degrees) to convert to radians.
     * 
     * @return The angle in radians.
     */
    static inline double degtorad(double angle)
    {
        return angle * k_degtorad;
    }

    /**
     * Converts the specified angle from radians to degrees.
     * 
     * @param angle The angle (in radians) to convert to degrees.
     * 
     * @return The angle in degrees.
     */
    static inline double radtodeg(double angle)
    {
        return angle * k_radtodeg;
    }

    /**
     * Rounds the specified value to the nearest integer.
     * 
     * @param value The value to round.
     * 
     * @return The rounded value.
     */
    static inline double round(double value)
    {
        return std::round(value);
    }

    /**
     * Rounds the specified value down to the nearest integer.
     * 
     * @param value The value to round down.
     * 
     * @return The rounded value.
     */
    static inline double floor(double value)
    {
        return std::floor(value);
    }

    /**
     * Rounds the specified value up to the nearest integer.
     * 
     * @param value The value to round up.
     * 
     * @return The rounded value.
     */
    static inline double ceil(double value)
    {
        return std::ceil(value);
    }

    /**
     * Clamps the specified value between a minimum and maximum range.
     * 
     * @param value The value to clamp.
     * @param min The minimum extent of the range.
     * @param max The maximum extent of the range.
     * 
     * @return The clamped value.
     */
    static inline double clamp(double value, double min, double max)
    {
        return value < min ? min : value > max ? max : value;
    }

    /**
     * Clamps the specified value between a minimum and maximum range.
     * 
     * @param value The value to clamp.
     * @param min The minimum extent of the range.
     * @param max The maximum extent of the range.
     * 
     * @return The clamped value.
     */
    static inline int clamp(int value, int min, int max)
    {
        return value < min ? min : value > max ? max : value;
    }

    /**
     * Performs a linear interpolation between the specified values.
     * 
     * @param a The first value.
     * @param b The second value.
     * @param amount The weight of the interpolation.
     *
     * @return The interpolated value.
     */
    static inline double lerp(double a, double b, double amount)
    {
        return a + (b - a) * amount;
    }
}

#endif