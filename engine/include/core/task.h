#ifndef DSE_TASK_H
#define DSE_TASK_H

#include <tbb/tbb.h>

namespace DSE {
    namespace Core {
        class Task {
            public:
                Task(void);
                ~Task(void);

                virtual void Execute(void) = 0;
            private:
                //
        };
        
        class SelfManagedTask : public tbb::task {
            public:
                SelfManagedTask(void);
                ~SelfManagedTask(void);
                
                virtual void Execute(void) = 0;
                tbb::task *execute(void);
            private:
                //
        };
    }
}

#endif
