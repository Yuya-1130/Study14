#pragma once
#include "Character.h"

// 魔法使い　派生クラス
class SMN : public Character
{
public:

	// 召喚士の情報
	SMN(const std::string& n, int power) : Character(n, Job::SMN, power) {}
};

