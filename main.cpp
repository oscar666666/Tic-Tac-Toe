#include <iostream>
#include "Player.h"
#include"PlayerHuman.h"
#include"PlayerRandom.h"
using namespace std;
void manvsman();
void computervscomputer();
void humanvscomputer();
int main() {
	cout << "Welcome to Tic-Tac-Toe" << endl
		<< " X go first" << endl
		<< "press 1 for man vs man," << endl
		<< "press 2 for man vs computer" << endl
		<< "press 3 for computer vs computer" << endl;
	int dd=0;
	cin >> dd;
	while (dd != 1 && dd != 2 && dd != 3) {//reject not valid input and let user input again
		cin >> dd;
		cout << "not valid enter again" << endl;
	}
	if (dd == 1)
		manvsman();
	else if (dd == 2)
		humanvscomputer();
	else if (dd == 3)
		computervscomputer();
	else {
		cout << "invalid input" << endl;
	}
	return 0;
}

void computervscomputer()
{int q = 1, w = 2;int count = 0;
	Board *k = new Board;
	Player *objA = new PlayerRandom(&q);	//objA->setposition(&q);
	Player *objB = new PlayerRandom(&w);	//objB->setposition(&w);	
     k->PrintBoard();
	while (k->DetermineWinner() != true && count <= 8) {
		objA->NextMove(*k);
		k->PrintBoard();
		count++;
		if (k->DetermineWinner() != true && count <= 8) {
			objB->NextMove(*k);
			k->PrintBoard();
			count++;
		}
	}
	if (k->printwinner(count, k) == 0)
		cout << "No winner." << endl;
	else if (k->printwinner(count, k) == 1)
		cout << "winner is:" << objB->getsymbol() << endl;
	else if (k->printwinner(count, k) == 2)
		cout << "winner is:" << objA->getsymbol() << endl;
	k->PrintBoard();
	delete k;
	delete objA;
	delete objB;
}

void humanvscomputer()
{
	Board *k = new Board;
	Player *objA ;
	Player *objB;
	k->PrintBoard();
	int q , w ;
	int count = 0;
	cout << "Do you want play X or O ?" << endl
		<< "1 for X, 2 for O" << endl;
	cin >> q;
	while (q!=1 && q!=2) {
		cout << "Invalid input. Please try again: ";
		cin >> q;
	}
	if (q == 1) {
		w = 2;
		 objA = new PlayerHuman(&q);	
		 objB = new PlayerRandom(&w);
	}
	else if(q==2) {
		w = 1;
		objA = new PlayerRandom(&q);
		objB = new PlayerHuman(&w);
	}
	while (k->DetermineWinner() != true && count <= 8) {
		objA->NextMove(*k);
		k->PrintBoard();
		count++;
		if (k->DetermineWinner() != true && count <= 8) {
			objB->NextMove(*k);
			k->PrintBoard();
			count++;
		}
	}
	if (k->printwinner(count, k) == 0)
		cout << "No winner." << endl;
	else if (k->printwinner(count, k) == 1)
		cout << "winner is:" << objB->getsymbol() << endl;
	else if (k->printwinner(count, k) == 2)
		cout << "winner is:" << objA->getsymbol() << endl;
	k->PrintBoard();
	delete k;
	delete objA;
	delete objB;
}

void manvsman() {
	Board *k = new Board;
	k->PrintBoard();
	int q = 1, w = 2;
	int count = 0;
	Player *objA = new PlayerHuman(&q);	//objA->setposition(&q);
	Player *objB = new PlayerHuman(&w);	//objB->setposition(&w);	
	while (k->DetermineWinner() != true && count <= 8) {
		objA->NextMove(*k);
		k->PrintBoard();
		count++;
		if (k->DetermineWinner() != true && count <= 8) {
			objB->NextMove(*k);
			k->PrintBoard();
			count++;
		}
	}
	if (k->printwinner(count, k) == 0)
		cout << "No winner." << endl;
	else if (k->printwinner(count, k) == 1)
		cout << "winner is:" << objB->getsymbol() << endl;
	else if (k->printwinner(count, k) == 2)
		cout << "winner is:" << objA->getsymbol() << endl;
	k->PrintBoard();
	delete k;
	delete objA;
	delete objB;
}

