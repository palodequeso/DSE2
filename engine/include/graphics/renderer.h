#ifndef DSE_RENDERER_H
#define DSE_RENDERER_H

#include "vulkan/vk_cpp.hpp"

namespace DSE {
    namespace Graphics {
        class Renderer {
            public:
                Renderer(void);
                ~Renderer(void);
            private:
                vk::ApplicationInfo *application_info;
                vk::Instance *instance;
                vk::InstanceCreateInfo *instance_info;
        };
    }
}

#endif
