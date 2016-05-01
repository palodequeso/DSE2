#include "engine/include/game/scene.h"

namespace DSE {
	namespace Game {
		Scene::Scene(void) {
			entities.clear();
		}

		Scene::~Scene(void) {
			auto iter = entities.begin();
			while (iter != entities.end()) {
				delete (*iter);
				iter++;
			}
			entities.clear();
		}
	}
}
