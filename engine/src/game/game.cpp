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
