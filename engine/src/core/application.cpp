#include "engine/include/core/application.h"

namespace DSE {
    namespace Core {
        Application::Application(DSE::Game::Game *_game) : game(_game) {
            running = true;
        }

        Application::~Application(void) {
            running = false;
        }

        void Application::Start(void) {
            while (running) {
                game->Update();
                //running = false;
            }
        }
    }
}
