#pragma once
#include "Board.h"
using namespace std;

class Player {
private:
	char *symbol;
	int *position;
public:
	Player();
	virtual ~Player();
	Player(char *p,int *q);
	Player(const Player &obj);
	Player& operator = (Player const& s) ;
	virtual void NextMove(const Board &obj) = 0;
	char getsymbol()const;
	int getposition()const;
	void setsymbol(char a);
	void setposition(int a);
};


