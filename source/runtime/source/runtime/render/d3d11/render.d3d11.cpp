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

#include <runtime/render.hpp>
#include <runtime/render/render.internal.hpp>
#include <runtime/render/d3d11/render.d3d11.hpp>
#include <runtime/window/window.internal.hpp>

namespace nezumi
{
    ID3D11Device*           g_d3d11_device;
    ID3D11DeviceContext*    g_d3d11_context;
    ID3D11RenderTargetView* g_d3d11_render_target;
    IDXGISwapChain*         g_d3d11_swap_chain;

    bool render_init()
    {
        // Setup Swap Chain Description
        DXGI_SWAP_CHAIN_DESC swap_chain_description
        {
            // Buffer Description
            {
                static_cast<UINT>(g_window_width),
                static_cast<UINT>(g_window_height),
                { 0, 1 },
                DXGI_FORMAT_R8G8B8A8_UNORM,
                DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED,
                DXGI_MODE_SCALING_UNSPECIFIED,
            },

            { 1, 0 },
            DXGI_USAGE_RENDER_TARGET_OUTPUT,
            1,
            reinterpret_cast<HWND>(g_window_handle),
            true,   // TODO: Add Fullscreen Support
            DXGI_SWAP_EFFECT_DISCARD,
            0,
        };

        // Set Feature Levels
        D3D_FEATURE_LEVEL feature_level = D3D_FEATURE_LEVEL_11_0;

        // Set Runtime Layers
        #ifdef DEBUG_MODE
            UINT flags = D3D11_CREATE_DEVICE_DEBUG;
        #else
            UINT flags = 0;
        #endif

        // Create Device and Swap Chain
        if (FAILED(D3D11CreateDeviceAndSwapChain(
            nullptr,
            D3D_DRIVER_TYPE_HARDWARE,
            nullptr,
            flags,
            &feature_level,
            1,
            D3D11_SDK_VERSION,
            &swap_chain_description,
            &g_d3d11_swap_chain,
            &g_d3d11_device,
            nullptr,
            &g_d3d11_context)))
        {
            // TODO: Display Error Dialog
            return false;
        }

        // Get Back Buffer Pointer
        ID3D11Texture2D* back_buffer_ptr;

        if (FAILED(g_d3d11_swap_chain->GetBuffer(0, __uuidof(ID3D11Texture2D), reinterpret_cast<void**>(&back_buffer_ptr))))
        {
            // TODO: Display Error Dialog
            return false;
        }

        // Create Render Target
        if (FAILED(g_d3d11_device->CreateRenderTargetView(back_buffer_ptr, nullptr, &g_d3d11_render_target)))
        {
            // TODO: Display Error Dialog
            return false;
        }

        // Release Back Buffer Pointer
        back_buffer_ptr->Release();

        // Set Render Target
        g_d3d11_context->OMSetRenderTargets(1, &g_d3d11_render_target, nullptr);

        // Success
        return true;
    }

    void render_swap_buffers()
    {
        // TODO: Add VSync Support
        g_d3d11_swap_chain->Present(0, 0);
    }

    void draw_clear(color_t color, float alpha)
    {
        // Make Raw Color
        FLOAT raw_color[]
        {
            color_get_red(color) / 255.0f,
            color_get_green(color) / 255.0f,
            color_get_blue(color) / 255.0f,
            alpha,
        };

        // Clear Render Target
        g_d3d11_context->ClearRenderTargetView(g_d3d11_render_target, raw_color);
    }
}