#include "PlayerRandom.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include<iostream>
PlayerRandom::PlayerRandom()
{
	playerNumber = NULL;
	//playerNumber = new int;//it is for other version of this program
}

PlayerRandom::~PlayerRandom()
{
	if (playerNumber != NULL)
		playerNumber = NULL;
		cout << "Destroying PlayerRandom";
}

PlayerRandom::PlayerRandom(int *p)
{
	playerNumber = p;
}

PlayerRandom::PlayerRandom(const PlayerRandom & obj)
{
	playerNumber = obj.playerNumber;
}

PlayerRandom & PlayerRandom::operator=(const PlayerRandom & s)
{
	if (this != &s)
	{
		delete playerNumber;
		playerNumber = new int;
		playerNumber = s.playerNumber;
	}
	return *this;
}

void PlayerRandom::NextMove(const Board & obj)
{
	int move;
	srand(time(0));
	move = rand() % 9;
	while (move<0 || move>9) {     //reject invalid input
		move = rand() % 9;
	}
	while (obj.getposition(move) != ' ') {
		move = rand() % 9;
	}
	//Player::setposition(playerNumber);
	if (*playerNumber == 1) { /*Player::getposition()*/
		Player::setsymbol('X');//set symbol to Player class
	}
	else if (*playerNumber == 2) {/*Player::getposition()*/
		Player::setsymbol('O');
	}
	obj.SetPosition( move, Player::getsymbol());//set position and symbol
}
