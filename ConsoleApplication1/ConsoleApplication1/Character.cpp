#include "Character.h"


 /// <summary>
 /// キャラの情報の初期化 名前、ジョブ、攻撃力
 /// </summary>
 /// <param name="n＝名前"></param>
 /// <param name="j＝ジョブ"></param>
 /// <param name="power＝攻撃力"></param>
 Character::Character(const std::string& n, Job j, int power) 
	   : name(n), job(j), attack_power(power) {}

 // 攻撃力を受け取る内容
 int Character::Getpower() const { return attack_power; }

 // ジョブを受け取る内容
 Job Character::GetJob() const { return job; }

 // 名前を受け取る内容
 const std::string& Character::GetName() const { return name; }

 // ジョブをわかりやすいように日本語にして返したい
 std::string Character::GetJobName() const {
	 
	 switch (job) {
	 case Job::SWD: return "剣士";
	 case Job::MAG: return "魔法使い";
	 case Job::SMN: return "召喚士";
	 
	 }
	 return "エラー";
 }

 



