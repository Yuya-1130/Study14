#pragma once
#include "Character.h"

// 魔法使い　派生クラス
class MAG : public Character
{
public:

	// 魔法使いの情報
	MAG(const std::string& n, int power) : Character(n, Job::MAG, power) {}
};

