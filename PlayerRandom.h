#pragma once
#include"Player.h"
class PlayerRandom :public Player {
private:
	int *playerNumber;
public:
	PlayerRandom();
	~PlayerRandom();
	PlayerRandom(int *p);
	PlayerRandom(const PlayerRandom &obj);
	PlayerRandom &operator =(const PlayerRandom & s);
	virtual void NextMove(const Board &obj);
};