#include <iostream>
#include "piece.h"
#include "memory.h"

#ifndef CHESS_H
#define CHESS_H

class Chess {

public:
	Chess();
	bool move(int fromX, int fromY, int toX, int toY);
	bool isCheck(int x, int y, Color color);
	bool isCheckmate(Color color);
	friend std::ostream &operator<<(std::ostream &output, const Chess &C);

private:
	Piece *board[8][8];
	int whiteKing[2] = {7, 4};
	int blackKing[2] = {0, 4};
};

#endif