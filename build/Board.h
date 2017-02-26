#pragma once
using namespace std;
const int n = 9;
class Board{
private:
	char *Pposition;
public:
	Board();
	~Board();
	Board(const Board &obj);
    Board& operator = (const Board & s);
	void PrintBoard();
	bool DetermineWinner();
	int printwinner(int count, Board * s);
	char getposition(int p)const;
	void SetPosition( int position,char player)const;
};