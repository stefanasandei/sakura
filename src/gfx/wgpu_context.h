//
// Created by Asandei Stefan on 07.08.2023.
//

#pragma once

#include "core/base.h"
#include "core/window.h"

#include <webgpu/webgpu.hpp>

#define WGPU_CHECK(x) if (!x) { \
            std::cerr << "WebGPU error at line " << __LINE__ << " in file " << __FILE__ << '\n'; \
            std::exit(-1); \
        }

namespace Sakura {
    class WGPUContext {
    public:
        explicit WGPUContext(const Window& window);
        ~WGPUContext();

        [[nodiscard]] Ref<wgpu::Device> GetDevice() const { return m_Device; }
        [[nodiscard]] Ref<wgpu::Surface> GetSurface() const { return m_Surface; }
        [[nodiscard]] wgpu::Queue GetQueue() const { return m_Device->getQueue(); }

    private:
        void SetDeviceCallbacks();

        Ref<wgpu::Instance> m_Instance;
        Ref<wgpu::Surface> m_Surface;
        Ref<wgpu::Adapter> m_Adapter;
        Ref<wgpu::Device> m_Device;
    };
}

