#ifndef DSE_RESOURCE_MANAGER_H
#define DSE_RESOURCE_MANAGER_H

#include "engine/include/core/system.h"
#include "engine/include/resources/resource.h"

namespace DSE {
    namespace Resources {
        class ResourceManager : public DSE::Core::SelfManagedSystem {
            public:
                ResourceManager(void);
                ~ResourceManager(void);

                void Run(void);
            private:
                //
        };
    }
}

#endif
