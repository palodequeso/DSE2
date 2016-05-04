#include "engine/include/game/game.h"

namespace DSE {
    namespace Game {
        Game::Game(Scene *_scene) : scene(_scene) {
            // Enqueued tasks must have the allowcate_root method called!
            resource_manager = new (tbb::task::allocate_root()) DSE::Resources::ResourceManager();
            DSEScheduler->AddTask(resource_manager);
            systems["renderer"] = new DSE::Graphics::Renderer();
            DSEScheduler->Start();
        }

        Game::~Game(void) {
            delete resource_manager;
        }
        
        void Game::Update(void) {
            auto system_iter = systems.begin();
            while (system_iter != systems.end()) {
                DSEScheduler->AddTask(system_iter->second);
                ++system_iter;
            }
            DSEScheduler->Execute(0.16f);
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
