//
// Created by Asandei Stefan on 07.08.2023.
//

#include "application.h"

namespace Sakura {
    Application::Application(const Sakura::ApplicationDescriptor &desc) {
        m_Window = CreateRef<Window>(WindowDescriptor {
            .Name = desc.Name,
            .Width = desc.Width,
            .Height = desc.Height
        });

        m_Renderer = MainRenderer::GetInstance(m_Window);
    }

    Application::~Application() {
        m_Renderer->Destroy();
    }

    void Application::PushLayer(Layer *layer) {
        m_Layers.emplace_back(layer);
    }

    int32_t Application::Run() {
        for(auto layer : m_Layers)
            layer->OnInit();

        while(!m_Window->ShouldClose()) {
            for(auto layer : m_Layers)
                layer->OnUpdate();

            m_Window->PollEvents();
        }

        for(auto layer : m_Layers) {
            layer->OnDestroy();
            delete layer;
        }

        return EXIT_SUCCESS;
    }
}