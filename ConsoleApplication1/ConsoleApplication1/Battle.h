#pragma once
#include "Character.h"
#include "Teams.h"

// 戦闘結果 ドロー、カウンター、クリティカル、攻撃が高い方
enum class Battle 
{
	Draw,
	Counter,
	Critical,
	HighAttack

};

// 戦闘の処理をするクラス
class BattleRes {

public:
	// ジョブの戦闘結果表
	static Battle Judge(Job atk, Job def);

	// ダメージを計算する
	static int Damage(Battle result, int attack_power);

	// 戦闘処理
	static void Process(Character* Player, Action PL_action,
	                    Character* Enemy, Action EN_action,
		                int& PL_Forece, int& EN_Forece);
};
