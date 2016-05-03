#include "engine/include/core/task.h"

namespace DSE {
    namespace Core {
        Task::Task(void) {
            //
        }

        Task::~Task(void) {
            //
        }

        SelfManagedTask::SelfManagedTask(void) : tbb::task() {
            //
        }

        SelfManagedTask::~SelfManagedTask(void) {
            //
        }

        tbb::task *SelfManagedTask::execute(void) {
            Execute();
            return nullptr;
        }
    }
}
