#ifndef DSE_SCHEDULER_H
#define DSE_SCHEDULER_H

#define DSEScheduler Scheduler::Instance()

#include <unordered_map>
#include "ctpl_stl.h"

namespace DSE {
    namespace Core {
        class Scheduler {
            public:
                Scheduler(void);
                ~Scheduler(void);
                
                static Scheduler *Instance();
                
                template<typename F, typename... Rest>
                auto AddTask(F && f, Rest &&... rest) -> std::future<decltype(f(0, rest...))>;
                
                template<typename F, typename ... Rest>
                void AddDedicatedTask(std::string name, F && f, Rest &&... rest);

            private:
                ctpl::thread_pool *pool;
                std::unordered_map<std::string, std::thread> dedicated_threads;
                
                static Scheduler *singleton_instance;
        };
    }
}

#endif
