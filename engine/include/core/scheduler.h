#ifndef DSE_SCHEDULER_H
#define DSE_SCHEDULER_H

#define DSEScheduler DSE::Core::Scheduler::Instance()

#include <unordered_map>
#include <tbb/tbb.h>

#include "engine/include/core/task.h"

namespace DSE {
    namespace Core {
        class Scheduler {
            public:
                Scheduler(void);
                ~Scheduler(void);
                
                static Scheduler *Instance();
                
                void AddTask(DSE::Core::Task *task);
                void AddTask(DSE::Core::SelfManagedTask *task);
                
                void Start(void);
                
                // Called by game to fire off sub-systems.
                void Execute(float frame_time);

                // Called by execute, but can also be called by sub-systems to split their own tasks.
                static void RunTasks(std::vector<DSE::Core::Task *> *tasks);

            private:

                std::vector<DSE::Core::SelfManagedTask *> self_managing_tasks;
                std::vector<DSE::Core::Task *> tasks;
                
                static Scheduler *singleton_instance;
        };
    }
}

#endif
