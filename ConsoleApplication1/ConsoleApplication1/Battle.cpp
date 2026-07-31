#include "Battle.h"
#include <iostream>

// ˆ—
Battle BattleRes::Judge(Job atk, Job def){

	
	// UŒ‚@‘Î@–hŒä@‚ÌðŒ
	if (atk == Job::SWD && def == Job::MAG) return Battle::Counter;
	if (atk == Job::SWD && def == Job::SMN) return Battle::Critical;

	if (atk == Job::MAG && def == Job::SMN) return Battle::Counter;
	if (atk == Job::MAG && def == Job::SWD) return Battle::Critical;

	if (atk == Job::SMN && def == Job::SWD) return Battle::Counter;
	if (atk == Job::SMN && def == Job::MAG) return Battle::Critical;
}

// ƒ_ƒ[ƒWŒvŽZ
int BattleRes::Damage(Battle result, int attack_power) {
	switch (result) {
		//@ƒNƒŠƒeƒBƒJƒ‹‚ÆƒJƒEƒ“ƒ^[‚Í‚Q”{
	case Battle::Critical:
	case Battle::Counter:
		return attack_power * 2;
		// ’ÊíUŒ‚
	case Battle::HighAttack:
		return attack_power;
	default:
		return 0;
	}
}
// í“¬ˆ—
void BattleRes::Process(Character* Player, Action PL_action,
	Character* Enemy, Action EN_action,
	int& PL_Force, int& EN_Force) {

	//UŒ‚“¯Žm
	if (PL_action == Action::Attack && EN_action == Action::Attack) {
		int Patk = Player->Getpower();
		int Eatk = Enemy->Getpower();

		if (Patk > Eatk) {
			EN_Force -= Patk;
			std::cout << "–¡•û‚ÌUŒ‚—Í‚ª‚‚¢‚½‚ßí“¬‚ÉŸ—˜F“Gí—ÍF-" << Patk << std::endl;
		}
		else if (Eatk > Patk) {
			PL_Force -= Eatk;
			std::cout << "“G‚ÌUŒ‚—Í‚ª‚‚¢‚½‚ßí“¬‚ÉŸ—˜F“Gí—ÍF-" << Eatk << std::endl;
		}
		else {
			std::cout << "UŒ‚—Í‚ª“¯‚¶‚¾I" << std::endl;
		}
	}
	//@UŒ‚@‘Î@–hŒä
	if (PL_action == Action::Attack && EN_action == Action::Defend) {
		Battle b = Judge(Player->GetJob(), Enemy->GetJob());
		int dmg = Damage(b, Player->Getpower());

		if (b == Battle::Counter) {
			PL_Force -= dmg;
			std::cout << "“G‚ÌƒJƒEƒ“ƒ^[F–¡•ûí—ÍF-" << dmg << std::endl;
		}
		else if (b == Battle::Critical) {
			EN_Force -= dmg;
			std::cout << "–¡•û‚ÌƒNƒŠƒeƒBƒJƒ‹F“Gí—ÍF-" << dmg << std::endl;
		}
		else {
			std::cout << "ƒhƒ[" << std::endl;
		}
		return;
	}
	// –hŒä@‘Î@UŒ‚
	if (PL_action == Action::Defend && EN_action == Action::Attack) {
		Battle b = Judge(Enemy->GetJob(), Player->GetJob());
		int dmg = Damage(b, Enemy->Getpower());

		if (b == Battle::Counter) {
			EN_Force -= dmg;
			std::cout << "–¡•û‚ÌƒJƒEƒ“ƒ^[F“Gí—ÍF-" << dmg << std::endl;
		}
		else if (b == Battle::Critical) {
			PL_Force -= dmg;
			std::cout << "“G‚ÌƒNƒŠƒeƒBƒJƒ‹F–¡•ûí—ÍF-" << dmg << std::endl;
		}
		else {
			std::cout << "ƒhƒ[" << std::endl;
		}
		return;
	}
	// –hŒä@‘Î@–hŒä
	std::cout << "—¼w‰c–hŒäFƒhƒ[" << std::endl;
}

