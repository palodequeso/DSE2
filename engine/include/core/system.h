#ifndef DSE_SYSTEM_H
#define DSE_SYSTEM_H

#include <vector>

#include "engine/include/core/component.h"

namespace DSE {
    namespace Core {
        class System {
            public:
                System(void);
                ~System(void);

                virtual void Run(void);
            protected:
                std::vector<Component *> components;
            private:
                //
        };
    }
}

#endif
