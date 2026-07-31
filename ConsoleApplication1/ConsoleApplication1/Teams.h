#pragma once
#include <vector>
#include <string>
#include "Character.h"

/// <summary>
/// チームクラス　キャラ管理＋行動処理
/// </summary>
class Teams
{
private:
	// 各陣営
	std::string name;
	// 戦力値
	int force_value;
	// チームメンバーを表示させる
	std::vector<Character*> members;

public:

	// コンストラクタ
	Teams(const std::string& n, int intialForce);
	~Teams();

	// キャラの所有権を移す
	void AddMember(Character* ch);

	// 選択したキャラを取得
	Character* GetMember(int index);

	// 戦力値を返す
	int GetForce() const;

	// 戦力値を減らす
	void FallForce(int value);

	// どっちの陣営かを返す
	const std::string& GetName() const;
	

};

