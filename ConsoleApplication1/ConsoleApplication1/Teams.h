#pragma once
class Teams
{
protected:
	int attack_damage;

public:
	void Action();

 	virtual void ActionExecute();

	virtual void CharacterName();
};

