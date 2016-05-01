#ifndef DSE_GAME_H
#define DSE_GAME_H

#include <unordered_map>

#include "engine/include/core/scheduler.h"
#include "engine/include/core/system.h"

#include "engine/include/game/scene.h"

namespace DSE {
    namespace Game {
        class Game {
            public:
                Game(Scene *_scene);
                ~Game(void);
                
                void Update(void);
                
                void RegisterSystem(std::string name, DSE::Core::System *system);

            protected:
                virtual void Logic(void);

            private:
				Scene *scene;
                std::unordered_map<std::string, DSE::Core::System *> systems;
        };
    }
}

#endif
