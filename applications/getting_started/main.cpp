#include <iostream>

#include "engine/include/core/application.h"
#include "engine/include/game/game.h"
#include "engine/include/game/scene.h"

int main(int argc, char **argv) {
	DSE::Game::Scene *scene = new DSE::Game::Scene();
    DSE::Game::Game *game = new DSE::Game::Game(scene);
    DSE::Core::Application *app = new DSE::Core::Application(game);
    app->Start();
    return 0;
}
