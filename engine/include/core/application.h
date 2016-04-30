#ifndef DSE_APPLICATION_H
#define DSE_APPLICATION_H

#include "engine/include/game/game.h"

namespace DSE {
    namespace Core {
        class Application {
            public:
                Application(DSE::Game::Game *_game);
                ~Application(void);

                void Start(void);
            private:
                DSE::Game::Game *game;
                bool running;
        };
    }
}

#endif
