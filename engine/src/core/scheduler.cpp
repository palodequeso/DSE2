#include "engine/include/core/scheduler.h"

namespace DSE {
	namespace Core {
		Scheduler::Scheduler(void) {
			pool = new ctpl::thread_pool(8);
		}

		Scheduler::~Scheduler(void) {
			delete pool;
		}
	}
}