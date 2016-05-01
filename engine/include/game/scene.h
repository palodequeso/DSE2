#ifndef DSE_SCENE_H
#define DSE_SCENE_H

#include <vector>
#include "engine/include/game/entity.h"

namespace DSE {
	namespace Game {
		class Scene {
			public:
				Scene(void);
				~Scene(void);
			private:
				std::vector<DSE::Game::Entity *> entities;
		};
	}
}

#endif
