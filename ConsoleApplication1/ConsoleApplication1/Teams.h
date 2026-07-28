#pragma once
#include <vector>
#include <memory>
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
	std::vector<std::unique_ptr<Character>> members;

public:

	// コンストラクタ
	Teams(const std::string& n, int intialForce);

	// キャラの所有権を移す
	void AddMember(std::unique_ptr<Character > ch);

	// 選択したキャラを取得
	Character* GetMember(int index);

	// 戦力値を返す
	int GetForce() const;

	// 戦力値を減らす
	void FallForce(int value);

	// どっちの陣営かを返す
	const std::string& GetName() const;
	

};

