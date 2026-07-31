#include <iostream>
#include "Teams.h"
#include "SWD.h"
#include "MAG.h"
#include "SMN.h"
#include "Trun.h"

int main() {

	// w‰c‚ğ¶¬
	Teams* PL = new Teams("©w‰c", 300);
	Teams* EN = new Teams("“Gw‰c", 300);

	// ƒLƒƒƒ‰‚ğ¶¬‚µ‚Ä’Ç‰Á‚·‚é
	PL->AddMember(new SWD("–¡•ûŒ•m", 36));
	PL->AddMember(new MAG("–¡•û–‚–@g‚¢", 32));
	PL->AddMember(new SMN("–¡•û¢Š«m", 32));

	EN->AddMember(new SWD("“GŒ•m", 36));
	EN->AddMember(new MAG("“G–‚–@g‚¢", 32));
	EN->AddMember(new SMN("“G¢Š«m", 32));

	// ƒ^[ƒ“ˆ—
	int turn = 1;
}