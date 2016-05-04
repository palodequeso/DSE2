#ifndef DSE_SYSTEM_H
#define DSE_SYSTEM_H

#include <tbb/tbb.h>
#include <vector>

#include "engine/include/core/task.h"
#include "engine/include/core/component.h"
#include "engine/include/core/scheduler.h"

namespace DSE {
    namespace Core {
        class System : public Task {
            public:
                System(void);
                ~System(void);

                virtual void Run(void);
                void Execute(void);

            protected:
                tbb::concurrent_vector<Component *> components;

            private:
                //
        };
        
        class SelfManagedSystem : public SelfManagedTask {
            public:
                SelfManagedSystem(void);
                ~SelfManagedSystem(void);
                
                virtual void Run(void);
                void Execute(void);

            protected:
                tbb::concurrent_vector<Component *> components;

            private:
                //
        };
    }
}

#endif
