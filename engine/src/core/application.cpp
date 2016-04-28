#include "engine/include/core/application.h"

namespace DSE {
    namespace Core {
        Application::Application(void) {
            running = true;
        }

        Application::~Application(void) {
            running = false;
        }

        void Application::Start(void) {
            while (running) {
                // Do Stuff
                running = false;
            }
        }
    }
}
