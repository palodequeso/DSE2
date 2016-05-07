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
            
            // Query how many devices are present in the system
            auto devices = instance->enumeratePhysicalDevices();
            unsigned int device_count = devices.size();
            if (device_count == 0) {
                std::cerr << "There are no vulkan capable physical devices!" << std::endl;
                abort();
            }
            
            std::cout << "Found " << device_count << " vulkan devices!" << std::endl;

            vk::DeviceQueueCreateInfo *device_queue_create_infos = new vk::DeviceQueueCreateInfo();
            vk::DeviceCreateInfo *device_create_info = new vk::DeviceCreateInfo(0, 1, &device_queue_create_infos, 0, nullptr, 0, nullptr, nullptr);
            vk::Device *device = nullptr;
            devices.at(0).createDevice(device_create_info, nullptr, device);
//             auto device_iter = devices.begin();
//             while (device_iter != devices.end()) {
//                 vk::PhysicalDevice *device = (*device_iter);
//                 device->getDisplayPropertiesKHR()
//                 ++device_iter;
//             }
        }

        Renderer::~Renderer(void) {
            delete instance;
        }
        
        void Renderer::Run(void) {
//             std::cout << "Rendering" << std::endl;
        }
    }
}
