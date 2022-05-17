/*
This file is a part of: Lina Engine
https://github.com/inanevin/LinaEngine

Author: Inan Evin
http://www.inanevin.com

Copyright (c) [2018-] [Inan Evin]

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

/*
Class: Application

Central application class, responsible for managing all the engines like input, physics, rendering etc.
as well as defining the game loop.

Timestamp: 12/29/2018 10:43:46 PM
*/

#pragma once
#ifndef LinaGUI_HPP
#define LinaGUI_HPP

#include "Common.hpp"
#include <functional>

namespace LinaVG
{
    /// <summary>
    /// Management for draw buffers.
    /// </summary>
    struct RendererData
    {
        Array<DrawBuffer>         m_defaultBuffers;
        Array<GradientDrawBuffer> m_gradientBuffers;
        Array<TextureDrawBuffer>  m_textureBuffers;
        Array<DrawBuffer*>        m_buffers;
        int                       m_gcFrameCounter;
        int                       m_minDrawOrder = -1;
        int                       m_maxDrawOrder = -1;

        void                SetDrawOrderLimits(int drawOrder);
        int                 GetBufferIndexInGradientArray(DrawBuffer* buf);
        int                 GetBufferIndexInTextureArray(DrawBuffer* buf);
        int                 GetBufferIndexInDefaultArray(DrawBuffer* buf);
        DrawBuffer&         GetDefaultBuffer(int drawOrder, DrawBufferShapeType shapeType);
        GradientDrawBuffer& GetGradientBuffer(Vec4Grad& grad, int drawOrder, DrawBufferShapeType shapeType);
        TextureDrawBuffer&  GetTextureBuffer(BackendHandle textureHandle, const Vec2& tiling, const Vec2& uvOffset, int drawOrder, DrawBufferShapeType shapeType);
    };

    namespace Internal
    {
        extern LINAVG_API RendererData g_rendererData;
    }

    LINAVG_API void                 Initialize();
    LINAVG_API void                 Terminate();
    LINAVG_API void                 StartFrame();
    LINAVG_API void                 Render();
    LINAVG_API void                 EndFrame();
    extern LINAVG_API Configuration Config;

}; // namespace LinaVG

#endif
