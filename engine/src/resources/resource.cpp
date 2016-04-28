#include "engine/include/resources/resource.h"

namespace DSE {
    namespace Resources {
        Resource::Resource(void) {
            type = ResourceType::TYPE_NONE;
            state = ResourceState::STATE_NONE;
        }

        Resource::~Resource(void) {
            //
        }

        Resource::ResourceType Resource::GetType(void) {
            return type;
        }

        Resource::ResourceState Resource::GetState(void) {
            return state;
        }
    }
}
