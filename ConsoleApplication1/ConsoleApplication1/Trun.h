#pragma once
#include "Teams.h"

// 1ターンの戦闘処理のクラス
class Turn
{
public:
	static void OneTurn(Teams& Player, Teams& Enemy, int turn);
};

