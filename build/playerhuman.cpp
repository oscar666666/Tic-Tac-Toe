#include<iostream>
#include"PlayerHuman.h"
PlayerHuman::PlayerHuman()
{
	playerNumber = NULL;
	//playerNumber = new int;//it is for other version of this program
}

PlayerHuman::~PlayerHuman()
{if(playerNumber!=NULL)
	 playerNumber=NULL;
	cout << "Destroying PlayerHuman";
}
PlayerHuman::PlayerHuman(int *p)
{
	playerNumber = p;
}
PlayerHuman::PlayerHuman(const PlayerHuman &obj) {
	playerNumber = obj.playerNumber;
}
PlayerHuman & PlayerHuman::operator=(const PlayerHuman & s)
{
	if (this != &s)
	{
		delete playerNumber;
		playerNumber = new int;
		playerNumber = s.playerNumber;
	}
	return *this; // TODO: insert return statement here
}
void PlayerHuman::NextMove(const Board & obj)
{
	int move;
	cout << "Next move(Ex. 0,1,2,3,4,5,6,7,8): ";
	cin >> move;
	while (move<0 || move>8) {//ASCII table 0=48 8=56 static_cast<int>(move) <48 && static_cast<int>(move)>56
		cout << "Invalid position. Please try again: ";
		cin >> move;
	}
	while (obj.getposition(move) != ' ') {
		cout << "That space has already been taken. Input again: ";
		cin >> move;
	}
	//Player::setposition(move);
	if (*playerNumber  == 1) {/*Player::getposition()*/
	
		Player::setsymbol('X');
	}
	else if (*playerNumber== 2) {/*Player::getposition()*/ 
		
		Player::setsymbol('O');
	}
	obj.SetPosition(move, Player::getsymbol());
}


