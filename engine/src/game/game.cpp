#include "engine/include/game/game.h"

namespace DSE {
    namespace Game {
        Game::Game(Scene *_scene) : scene(_scene) {
            //
        }
        
        Game::~Game(void) {
            //
        }
        
        void Game::Update(void) {
            auto system_iter = systems.begin();
            while (system_iter != systems.end()) {
                DSEScheduler->AddTask(system_iter->second);
            }
            Logic();
        }

        void Game::RegisterSystem(std::string name, DSE::Core::System *system) {
            systems[name] = system;
        }
        
        void Game::Logic(void) {
            //
        }
    }
}
