#pragma once
#include "Character.h"

// Œ•m ”h¶ƒNƒ‰ƒX
class SWD : public Character
{
public:
	// Œ•m‚Ìî•ñ
	SWD(const std::string& n, int power): Character(n, Job::SWD, power){}
};

