#include <iostream>
#include <thread>

#include "engine/include/resources/resource_manager.h"
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
            int thread_count = tbb::task_scheduler_init::default_num_threads();
            std::cout << "Firing up " << thread_count << " threads!" << std::endl;
        }

        Scheduler::~Scheduler(void) {
            //
        }
        
        void Scheduler::AddTask(DSE::Core::Task *task) {
            tasks.push_back(task);
        }

        void Scheduler::AddTask(DSE::Core::SelfManagedTask *task) {
            self_managing_tasks.push_back(task);
        }
        
        void Scheduler::Start(void) {
            // We probably don't have to use tbb enqueue here. but I did not take the time to find an alt yet
            auto task_iter = self_managing_tasks.begin();
            while (task_iter != self_managing_tasks.end()) {
                tbb::task *task = static_cast<tbb::task *>(*task_iter);
                tbb::task::enqueue(*task, tbb::priority_low);
                ++task_iter;
            }
        }

        void Scheduler::RunTasks(std::vector<DSE::Core::Task *> *tasks) {
            tbb::parallel_do(tasks->begin(), tasks->end(), [&](DSE::Core::Task *task) {
                task->Execute();
            });
        }

        void Scheduler::Execute(float frame_time) {
            std::thread t(Scheduler::RunTasks, &tasks);
            t.join();
        }

    }
}
