#include "Judge.h"
#include <cstdlib>
#include <ctime>

int Random::Range(int min, int max) {


	static bool ram = false;

	if (!ram) {
		std::srand(std::time(nullptr));
		ram = true;
	}

	// ƒ‰ƒ“ƒ_ƒ€‚Ì”ÍˆÍŽw’è
	return std::rand() % (max - min + 1) + min;
}

