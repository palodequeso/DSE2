#include <iostream>
#include "engine/include/graphics/renderer.h"

namespace DSE {
    namespace Graphics {
        Renderer::Renderer(void) {
            application_info = new vk::ApplicationInfo("DSE Renderer", 0, "DSE", 0, 0);
            instance_info = new vk::InstanceCreateInfo(vk::InstanceCreateFlags(), application_info, 0, nullptr, 0, nullptr);
            instance = new vk::Instance();

            // Now create the desired instance
            vk::Result result = vk::createInstance(instance_info, nullptr, instance);
            if (result != vk::Result::eSuccess) {
                std::cerr << "Failed to create instance: " << result << std::endl;
                abort();
            }
        }

        Renderer::~Renderer(void) {
            delete instance;
        }
        
        void Renderer::Run(void) {
            //
        }
    }
}
