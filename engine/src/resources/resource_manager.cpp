#include "engine/include/resources/resource_manager.h"
#include <SFML/System.hpp>

namespace DSE {
    namespace Resources {
        ResourceManager::ResourceManager(void) : DSE::Core::SelfManagedSystem() {
            //
        }

        ResourceManager::~ResourceManager(void) {
            //
        }

        void ResourceManager::Run(void) {
            while (true) {
                std::cout << "Checking for new resources..." << std::endl;
                tbb::parallel_do(components.begin(), components.end(), [&](DSE::Core::Component *component) {
                    auto resource = static_cast<Resource *>(component);
                    if (resource->GetState() == DSE::Resources::Resource::STATE_NONE) {
                        // Start Loading
                        if (resource->GetType() == DSE::Resources::Resource::TYPE_TEXT) {
                            // Load Text
                        } else if (resource->GetType() == DSE::Resources::Resource::TYPE_IMAGE) {
                            // Load Image
                        }
                    } else if (resource->GetState() == DSE::Resources::Resource::STATE_LOADING) {
                        // Check if done
                    }
                });
                sf::sleep(sf::seconds(1.0f));
            }
        }
    }
}