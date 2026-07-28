#include "Teams.h"
#include <iostream>

// w‰c‚Ì‰Šú‰»
Teams::Teams(const std::string& n, int intialForce)
	: name(n), force_value(intialForce) {}


void Teams::AddMember(std::unique_ptr<Character > ch) {
	// ƒLƒƒƒ‰‚ğw‰c‚É’Ç‰Á
	members.push_back(std::move(ch));
}


Character* Teams::GetMember(int index) {
	// w’è‚µ‚½‚P`‚R‚Ì”Ô†‚ÌƒLƒƒƒ‰‚ğæ“¾
	// ¶ƒ|ƒCƒ“ƒ^‚ğ‚Â‚©‚Á‚Ä•Ô‚·
	return members[index].get();
}

int Teams::GetForce() const {
	// Œ»İ‚Ìí—Í’l‚ğ•Ô‚·
	return force_value;
}

void Teams::FallForce(int fall_value) {
	// í—Í’l‚ğŒ¸‚ç‚·
	force_value -= fall_value;
	
	// 0‚æ‚è‰º‚É‚È‚ç‚È‚¢‚æ‚¤‚É‚·‚é
	if (force_value < 0) force_value = 0;
}

const std::string& Teams::GetName() const {

	// w‰c–¼‚ğ•Ô‚·
	return name;
}