#pragma once
#include <string>

// 行動の種類
enum class Action
{
	// 攻撃と防御
	Attack,
	Defend
};

// ジョブの種類
enum class Job
{
	// 剣士、魔法使い、召喚士
	SWD,
	MAG,
	SMN
};

// キャラクタークラス（基底クラス）
class Character
{
	
protected:
	// 攻撃力 (継承用でprotectedを活用する)
	int attack_power;
	// 職業
	Job job;
	// 名前表示
	std::string name;

public:
	// 攻撃力のコンストラクタ
	Character(const std::string& n, Job j, int power);

	// デストラクタ
	virtual ~Character() = default;

	// 攻撃力を受け取る
	int Getpower() const;

	// ジョブを受け取る
	Job GetJob() const;

	// 名前を受け取る
	const std::string& GetName() const;

	// ジョブ名を返す
	//std::string GetJobName() const;
};

