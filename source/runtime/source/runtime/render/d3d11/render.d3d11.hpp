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

#ifndef NEZUMI_RUNTIME_RENDER_D3D11_HPP
#define NEZUMI_RUNTIME_RENDER_D3D11_HPP

#include <d3d11.h>
#include <dxgi.h>

namespace nezumi
{
    /** The D3D11 device. */
    extern ID3D11Device* g_d3d11_device;

    /** The D3D11 device context. */
    extern ID3D11DeviceContext* g_d3d11_context;

    /** The D3D11 render target. */
    extern ID3D11RenderTargetView* g_d3d11_render_target;

    /** The D3D11 swap chain. */
    extern IDXGISwapChain* g_d3d11_swap_chain;
}

#endif