#include "engine\include\resources\resource_manager.h"

namespace DSE {
	namespace Resources {
		ResourceManager::ResourceManager(void) : DSE::Core::System() {
			//
		}

		ResourceManager::~ResourceManager(void) {
			//
		}

		void ResourceManager::Run(void) {
			auto component_iterator = components.begin();
			while (component_iterator != components.end()) {
				auto component = static_cast<Resource *>(*component_iterator);
				if (component->GetState() == DSE::Resources::Resource::STATE_NONE) {
					// Start Loading
					if (component->GetType() == DSE::Resources::Resource::TYPE_TEXT) {
						// Load Text
					} else if (component->GetType() == DSE::Resources::Resource::TYPE_IMAGE) {
						// Load Image
					}
				} else if (component->GetState() == DSE::Resources::Resource::STATE_LOADING) {
					// Check if done
				}
				component_iterator++;
			}
		}
	}
}