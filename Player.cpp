#include <iostream>
#include "Player.h"

using namespace std;
Player::Player() {
	symbol = new char;
	position = new int;
}
Player::~Player() {
	delete symbol ;
	delete position ;
	cout << "Destroying Player.h";
}
Player::Player(char *p,int *q) {
	symbol = p;
	position = q;
}
Player::Player(const Player &obj) {
	symbol = obj.symbol;
	position = obj.position;
}

Player & Player::operator=(Player const & s)
{
	if (this != &s)
	{
		delete symbol;
		delete position;
		symbol = new char;
		position = new int;
		symbol = s.symbol;
		position = s.position;
	}
	return *this;// TODO: insert return statement here
}
char Player::getsymbol()const {
	return *symbol;
}
int Player::getposition()const {
	return *position;
}
void Player::setsymbol(char a) {
	*symbol = a;
}
void Player::setposition(int a) {
	*position = a;
}
