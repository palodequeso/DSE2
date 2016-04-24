#ifndef DSE_RESOURCE_H
#define DSE_RESOURCE_H

#include <iostream>

#include "engine/include/core/component.h"
#include "engine/include/resources/resource.h"

namespace DSE {
	namespace Resources {
		class Resource : public DSE::Core::Component {
			public:
				enum ResourceType {
					TYPE_NONE = 0,
					TYPE_TEXT,
					TYPE_IMAGE
				};

				enum ResourceState {
					STATE_NONE = 0,
					STATE_LOADING,
					STATE_LOADED
				};

				Resource(void);
				~Resource(void);

				ResourceType GetType(void);
				ResourceState GetState(void);
			protected:
				ResourceType type;
				ResourceState state;
				std::string path;
			private:
				//
		};
	}
}

#endif
