#include <iostream>
#include "Teams.h"
#include "SWD.h"
#include "MAG.h"
#include "SMN.h"
#include "Trun.h"

int main() {

	// w‰c‚ð¶¬
	Teams* PL = new Teams("Ž©w‰c", 300);
	Teams* EN = new Teams("“Gw‰c", 300);

	// ƒLƒƒƒ‰‚ð¶¬‚µ‚Ä’Ç‰Á‚·‚é
	PL->AddMember(new SWD("–¡•ûŒ•Žm", 36));
	PL->AddMember(new MAG("–¡•û–‚–@Žg‚¢", 32));
	PL->AddMember(new SMN("–¡•û¢Š«Žm", 32));

	EN->AddMember(new SWD("“GŒ•Žm", 36));
	EN->AddMember(new MAG("“G–‚–@Žg‚¢", 32));
	EN->AddMember(new SMN("“G¢Š«Žm", 32));

	// ƒ^[ƒ“ˆ—
	int turn = 1;
	while (PL->GetForce() > 0 && EN->GetForce() > 0) {
		Turn::OneTurn(*PL, *EN, turn);
		turn++;
	}

	std::cout << "ƒŠƒUƒ‹ƒg" << std::endl;

	if (PL->GetForce() <= 0) {
		std::cout << "“Gw‰c‚ÌŸ—˜" << std::endl;
	}
	else {
		std::cout << "–¡•ûw‰c‚ÌŸ—˜" << std::endl;
	}
}