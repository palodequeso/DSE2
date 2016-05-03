#ifndef DSE_RENDERER_H
#define DSE_RENDERER_H

#include "vulkan/vk_cpp.hpp"
#include "engine/include/core/system.h"

namespace DSE {
    namespace Graphics {
        class Renderer : public DSE::Core::System {
            public:
                Renderer(void);
                ~Renderer(void);
                
                void Run(void);
            private:
                vk::ApplicationInfo *application_info;
                vk::Instance *instance;
                vk::InstanceCreateInfo *instance_info;
        };
    }
}

#endif
