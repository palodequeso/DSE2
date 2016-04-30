#include "engine/include/core/scheduler.h"

namespace DSE {
    namespace Core {
        Scheduler *Scheduler::singleton_instance = NULL;

        Scheduler *Scheduler::Instance() {
            if (!singleton_instance) {
                singleton_instance = new Scheduler();
            }
            return singleton_instance;
        }
        
        Scheduler::Scheduler(void) {
            pool = new ctpl::thread_pool(8);
            dedicated_threads.clear();
        }

        Scheduler::~Scheduler(void) {
            delete pool;
            dedicated_threads.clear();
        }
        
        template<typename F, typename... Rest>
        auto Scheduler::AddTask(F && f, Rest &&... rest) -> std::future<decltype(f(0, rest...))> {
            return pool->push(f, rest...);
        }
        
        template<typename F, typename... Rest>
        void Scheduler::AddDedicatedTask(std::string name, F && task, Rest &&... rest) {
            dedicated_threads[name] = std::thread(task, rest...);
        }

    }
}
