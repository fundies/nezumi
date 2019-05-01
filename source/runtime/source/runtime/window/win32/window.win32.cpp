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
#include <runtime/math.hpp>

#include <windows.h>

namespace nezumi
{
    // The name of the window class.
    static constexpr const char* class_name = "main";

    // The style of the window.
    static DWORD style;

    // Translates a Win32 keycode to its corresponding Nezumi keycode.
    static inline int translate_key(WPARAM wp)
    {
        // TODO: Maybe use a lookup table instead of a switch.
        switch (wp)
        {
            case VK_LEFT:       return vk_left;
            case VK_RIGHT:      return vk_right;
            case VK_DOWN:       return vk_down;
            case VK_UP:         return vk_up;
            case VK_RETURN:     return vk_enter;
            case VK_ESCAPE:     return vk_escape;
        }

        // Return "none" for any unknown keys.
        return vk_none;
    }

    // The main window procedure callback.
    static LRESULT CALLBACK window_procedure(HWND wnd, UINT msg, WPARAM wp, LPARAM lp)
    {
        switch (msg)
        {
            // The close button was pressed.
            case WM_CLOSE:
            {
                PostQuitMessage(0);

                return 0;
            }

            // The size was changed.
            case WM_SIZE:
            {
                g_window_width = LOWORD(lp);
                g_window_height = HIWORD(lp);

                return 0;
            }

            // The position was changed.
            case WM_MOVE:
            {
                g_window_x = static_cast<short>(LOWORD(lp));
                g_window_y = static_cast<short>(HIWORD(lp));

                return 0;
            }

            // The focus was changed.
            case WM_ACTIVATEAPP:
            {
                g_window_focus = wp;

                return 0;
            }

            // A key was pressed or released.
            case WM_KEYDOWN:
            case WM_KEYUP:
            {
                int key = translate_key(wp);

                if (key != vk_none)
                    g_keyboard_current[key] = (msg == WM_KEYDOWN);

                return 0;
            }

            // The left mouse button was pressed.
            case WM_LBUTTONDOWN:
            {
                // Set State
                g_mouse_current[mb_left] = true;

                // Set Capture
                SetCapture(reinterpret_cast<HWND>(g_window_handle));

                return 0;
            }

            // The left mouse button was released.
            case WM_LBUTTONUP:
            {
                // Reset State
                g_mouse_current[mb_left] = false;

                // Reset Capture
                if ((wp & (MK_RBUTTON | MK_MBUTTON)) == 0)
                    ReleaseCapture();

                return 0;
            }

            // The right mouse button was pressed.
            case WM_RBUTTONDOWN:
            {
                // Set State
                g_mouse_current[mb_right] = true;

                // Set Capture
                SetCapture(reinterpret_cast<HWND>(g_window_handle));

                return 0;
            }

            // The right mouse button was released.
            case WM_RBUTTONUP:
            {
                // Reset State
                g_mouse_current[mb_right] = false;

                // Reset Capture
                if ((wp & (MK_LBUTTON | MK_MBUTTON)) == 0)
                    ReleaseCapture();

                return 0;
            }

            // The middle mouse button was pressed.
            case WM_MBUTTONDOWN:
            {
                // Set State
                g_mouse_current[mb_middle] = true;

                // Set Capture
                SetCapture(reinterpret_cast<HWND>(g_window_handle));

                return 0;
            }

            // The middle mouse button was released.
            case WM_MBUTTONUP:
            {
                // Reset State
                g_mouse_current[mb_middle] = false;

                // Reset Capture
                if ((wp & (MK_LBUTTON | MK_RBUTTON)) == 0)
                    ReleaseCapture();

                return 0;
            }

            // The mouse position was changed.
            case WM_MOUSEMOVE:
            {
                // Sometimes these positions lie slightly outside of the client
                // area of the window, so we should manually clamp them ourselves.
                g_mouse_x = clamp(static_cast<short>(LOWORD(lp)), 0, g_window_width);
                g_mouse_y = clamp(static_cast<short>(HIWORD(lp)), 0, g_window_height);

                return 0;
            }
        }

        // Let Windows handle everything else.
        return DefWindowProcA(wnd, msg, wp, lp);
    }

    bool window_init(const char* title, int width, int height)
    {
        // Get Application Instance
        HINSTANCE instance = GetModuleHandleA(nullptr);

        // Get Window Style
        style = WS_OVERLAPPEDWINDOW & ~(WS_THICKFRAME | WS_MAXIMIZEBOX);

        // Get Window Area
        RECT area
        {
            0,
            0,
            width,
            height,
        };

        AdjustWindowRect(&area, style, false);

        // Create Window Class
        WNDCLASSA wc
        {
            CS_HREDRAW | CS_VREDRAW,
            window_procedure,
            0,
            0,
            instance,
            LoadIconA(nullptr, IDI_APPLICATION),
            LoadCursorA(nullptr, IDC_ARROW),
            nullptr,
            nullptr,
            class_name,
        };

        if (!RegisterClassA(&wc))
        {
            // TODO: Display Error Dialog
            return false;
        }

        // Create Window
        g_window_handle = CreateWindowExA
        (
            0,
            class_name,
            title,
            style,
            0,
            0,
            area.right - area.left,
            area.bottom - area.top,
            nullptr,
            nullptr,
            instance,
            nullptr
        );

        if (g_window_handle == nullptr)
        {
            // TODO: Display Error Dialog
            return false;
        }

        // Center Window
        g_window_width = width;
        g_window_height = height;

        window_center();

        // Success
        return true;
    }

    bool window_events()
    {
        MSG msg;

        // Message Loop
        while (PeekMessageA(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            // The close button was pressed.
            if (msg.message == WM_QUIT)
                return false;

            // Translate and dispatch the message.
            TranslateMessage(&msg);
            DispatchMessageA(&msg);
        }

        return true;
    }

    void window_center()
    {
        SetWindowPos
        (
            reinterpret_cast<HWND>(g_window_handle),
            HWND_TOP,
            (GetSystemMetrics(SM_CXSCREEN) - g_window_width) / 2,
            (GetSystemMetrics(SM_CYSCREEN) - g_window_height) / 2,
            0,
            0,
            SWP_NOSIZE
        );
    }

    void window_set_title(const char* title)
    {
        SetWindowTextA(reinterpret_cast<HWND>(g_window_handle), title);
    }

    void window_set_size(int width, int height)
    {
        // Get Window Area
        RECT area
        {
            0,
            0,
            width,
            height,
        };

        AdjustWindowRect(&area, style, false);

        // Set Window Size
        SetWindowPos
        (
            reinterpret_cast<HWND>(g_window_handle),
            HWND_TOP,
            0,
            0,
            area.right - area.left,
            area.bottom - area.top,
            SWP_NOMOVE
        );
    }

    void window_set_position(int x, int y)
    {
        SetWindowPos
        (
            reinterpret_cast<HWND>(g_window_handle),
            HWND_TOP,
            x,
            y,
            0,
            0,
            SWP_NOSIZE
        );
    }

    void window_set_visible(bool visible)
    {
        ShowWindow(reinterpret_cast<HWND>(g_window_handle), visible ? SW_SHOW : SW_HIDE);
    }

    void window_set_fullscreen(bool fullscreen)
    {
        // TODO: Add Fullscreen Support
    }
}