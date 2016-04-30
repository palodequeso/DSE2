#include <iostream>

#include "engine/include/core/application.h"
#include "engine/include/game/game.h"

int main(int argc, char **argv) {
    DSE::Game::Game *game = new DSE::Game::Game();
    DSE::Core::Application *app = new DSE::Core::Application(game);
    app->Start();
    return 0;
}
