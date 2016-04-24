#ifndef DSE_SCHEDULER_H
#define DSE_SCHEDULER_H

#include "ctpl_stl.h"

namespace DSE {
	namespace Core {
		class Scheduler {
			public:
				Scheduler(void);
				~Scheduler(void);
			private:
				ctpl::thread_pool *pool;
		};
	}
}

#endif
