#ifndef DSE_SYSTEM_H
#define DSE_SYSTEM_H

#include "tbb/tbb.h"
#include "engine/include/core/component.h"

namespace DSE {
    namespace Core {
        class System : public tbb::task {
            public:
                System(void);
                ~System(void);

				tbb::task *execute(void);
            private:
				tbb::concurrent_vector<Component *> components;
        };
    }
}

#endif
