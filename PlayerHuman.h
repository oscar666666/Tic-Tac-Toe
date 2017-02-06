#pragma once
#include"Player.h"
class PlayerHuman :public Player {
private:
	int *playerNumber;
public:
	PlayerHuman();
	~PlayerHuman();
	PlayerHuman(int *p);
	PlayerHuman(const PlayerHuman &obj);
	PlayerHuman& operator = (const PlayerHuman & s);
	virtual void NextMove(const Board &obj);
};