#include "Trun.h"
#include "Judge.h"
#include "Battle.h"
#include <iostream>


void Turn::OneTurn(Teams& Player, Teams& Enemy, int turn) {

	std::cout << "\n===== ƒ^[ƒ“ " << turn << " =====\n";

	// –¡•û‚ÌƒLƒƒƒ‰‚ğ‘I‘ğ‚·‚é‚O`‚Q‚Å
	std::cout << "ƒWƒ‡ƒu‚Ì‘I‘ği0.Œ•m 1.–‚–@g‚¢ 2.¢Š«m";
	int pl;
	std::cin >> pl;
	if (pl < 0 || pl > 2) pl = 0;

	Character* P = Player.GetMember(pl);

	// –¡•û‚Ìs“®‚ğ‘I‘ğ‚·‚éi‚Por2)1.UŒ‚@2.–hŒä
	std::cout << "s“®‚ğ‘I‘ğ@i0.UŒ‚ 1.–hŒäj";
	int action;
	std::cin >> action;
	Action PL_action = (action == 0) ? Action::Attack : Action::Defend;

	// “Gw‰c‚Ìƒ‰ƒ“ƒ_ƒ€‘I‘ğ
	// ƒLƒƒƒ‰‘I‘ğ
	int el = Random::Range(0, 2);
	Character* E = Enemy.GetMember(el);

	// s“®‘I‘ğ
	Action EN_action = (Random::Range(0, 1) == 0) ? Action::Attack : Action::Defend;

	// s“®Œ‹‰Ê‚ğ•\¦
	std::cout << "©w‰cF" << P->GetName() 
		<< "" << P->GetJobName() << ((PL_action == Action::Attack) ? "UŒ‚" : "–hŒä") << std::endl;

	std::cout << "“Gw‰cF" << E->GetName() 
		<< "" << E->GetJobName() << ((EN_action == Action::Attack) ? "UŒ‚" : "–hŒä") << std::endl;

	// í“¬ˆ—
	int P_Force = Player.GetForce();
	int E_Force = Enemy.GetForce();

	BattleRes::Process(P, PL_action, E, EN_action, P_Force, E_Force);

	//Œ»İ‚Ìí—Í‚ğ”½‰f‚³‚¹‚é
	Player.FallForce(Player.GetForce() - P_Force);
	Enemy.FallForce(Enemy.GetForce() - E_Force);

	// í—Í‚ğ•\¦
	std::cout << "©w‰cí—Í:" << Player.GetForce()
		<< "“Gí—ÍF" << Enemy.GetForce() << std::endl;
		 
}





