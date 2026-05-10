#include <iostream>
#include <C:\Users\fingx\OneDrive\Dokumente\Programming\C++\Snake Game\decla.h>
using namespace std;
int main() {
	Game game;
	bool success = game.Initialize();
	if (success) {
		game.Runloop();
	}
	game.Endloop();
	return 0;
}

