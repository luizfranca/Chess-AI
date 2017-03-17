#include <iostream>
#include "piece.h"
#include "memory.h"

#ifndef CHESS_H
#define CHESS_H

class Chess {

public:
	Chess();
	friend std::ostream &operator<<(std::ostream &output, const Chess &C);

private:
	std::unique_ptr<Piece> board[8][8];
};

#endif