#include <chrono>
#include "Terminal.h"
#include "Game.h"

int main()
{
    Terminal term(40,20);
    Game game(term);

    using namespace std::chrono;
    using fmilli = duration<float, seconds::period>;

    auto t0 = high_resolution_clock::now();
    auto t1 = high_resolution_clock::now();

	while (!game.is_done()) {
        t0 = t1;
        t1 = high_resolution_clock::now();
        game.update(fmilli(t1 - t0).count());
        game.draw();
	}

    term.close();
	return 0;
}
