#include <iostream>

#include "engine/include/core/application.h"

int main(int argc, char **argv) {
	DSE::Core::Application *app = new DSE::Core::Application();
	app->Start();
	return 0;
}
