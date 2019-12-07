#include <iostream>
#include "Board.h"

using namespace std;

Board::Board() {
	Pposition = new char[n];
	for (int i = 0; i<n; i++)
		Pposition[i] = ' ';
}
Board::~Board() {
	delete[] Pposition;
}
Board::Board(const Board &obj) {
	Pposition = new char[n];
	for (int i = 0; i<n; i++)
		Pposition[i] = obj.Pposition[i];

}
Board & Board::operator = (const Board & obj)
// assignment operator
{
	if (this != &obj)
	{
		delete Pposition;
		Pposition = new char[n];
		for (int i = 0; i < n; i++)
			Pposition[i] = obj.Pposition[i];
	}
	return *this;
}
void Board::PrintBoard() {//print the board
	cout << "+---+---+---+" << endl;
	cout << "|" << Pposition[0] << "  |" << Pposition[1] << "  |" << Pposition[2] << "  |" << endl;
	cout << "+---+---+---+" << endl;
	cout << "|" << Pposition[3] << "  |" << Pposition[4] << "  |" << Pposition[5] << "  |" << endl;
	cout << "+---+---+---+" << endl;
	cout << "|" << Pposition[6] << "  |" << Pposition[7] << "  |" << Pposition[8] << "  |" << endl;
	cout << "+---+---+---+" << endl;

}
char Board::getposition(int p)const {
	return Pposition[p];

}
bool Board::DetermineWinner() {//return true if we have winner function printwinner determine we have winner or not
	if (Pposition[0] == Pposition[1] && Pposition[0] == Pposition[2] && Pposition[0] != ' ')
		return true;
	else if (Pposition[3] == Pposition[4] && Pposition[3] == Pposition[5] && Pposition[3] != ' ')
		return true;
	else if (Pposition[6] == Pposition[7] && Pposition[6] == Pposition[8] && Pposition[6] != ' ')
		return true;
	else if (Pposition[0] == Pposition[4] && Pposition[0] == Pposition[8] && Pposition[0] != ' ')
		return true;
	else if (Pposition[2] == Pposition[4] && Pposition[2] == Pposition[6] && Pposition[2] != ' ')
		return true;
	else if (Pposition[0] == Pposition[3] && Pposition[0] == Pposition[6] && Pposition[0] != ' ')
		return true;
	else if (Pposition[1] == Pposition[4] && Pposition[1] == Pposition[7] && Pposition[1] != ' ')
		return true;
	else if (Pposition[2] == Pposition[5] && Pposition[2] == Pposition[8] && Pposition[2] != ' ')
		return true;

	return false;
}

int Board::printwinner(int count,  Board *s)//determine we have winner or not
{
	if (s->DetermineWinner() != true) {
		/*cout << "No winner." << endl;*/
		return 0;
	}
	else if (s->DetermineWinner() == true) {
		if (count % 2 == 0)
			return 1;/* cout << "winner is:" << objB->getsymbol() << endl;*/
		else if (count % 2 != 0)
			return 2; /*cout << "winner is:" << objA->getsymbol() << endl;*/
	}
}

void Board::SetPosition(int position,char player) const{//set symbol to the board

	if (Pposition[position] == ' ') {
		Pposition[position] = player;
	}
	else if (Pposition[position] != ' ') {
		cout << "error" << endl;
	}
}

