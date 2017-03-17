#include "chess.h"

using namespace std;

Chess::Chess() {
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			board[i][j] = nullptr;
		}
	}
	for (int i = 0; i < 8; ++i)
	{
		board[1][i] = new Pawn(BLACK);
		board[6][i] = new Pawn(WHITE);
		if (i == 0 || i == 7) {
			board[0][i] = new Rook(BLACK);
			board[7][i] = new Rook(WHITE);
		} else if (i == 1 || i == 6) {
			board[0][i] = new Knight(BLACK);
			board[7][i] = new Knight(WHITE);
		} else if (i == 2 || i == 5) {
			board[0][i] = new Bishop(BLACK);
			board[7][i] = new Bishop(WHITE);
		} else if (i == 3) {
			board[0][i] = new Queen(BLACK);
			board[7][i] = new Queen(WHITE);
		} else {
			board[0][i] = new King(BLACK);
			board[7][i] = new King(WHITE);	
		}
	}
}

bool Chess::move(int fromX, int fromY, int toX, int toY) {
	if (fromX > 7 || fromX < 0 || fromY > 7 || fromY < 0 || toX > 7 || toX < 0 || toY > 7 || toY < 0) {
		return false;
	} else if (board[fromX][fromY]->isValid(fromX, fromY, toX, toY, board)) {
		delete board[toX][toY];
		board[toX][toY] = board[fromX][fromY];
		board[fromX][fromY] = nullptr;
		return true;
	}

	return false;
}

bool Chess::isCheck(int x, int y, Color color) {
	return false;
}

bool Chess::isCheckmate(Color color) {
	int *king = color == WHITE ? whiteKing : blackKing;

	if (this->isCheck(king[0], king[1], color)) {
		return true;
	}
	return false;
}

ostream &operator<<( ostream &output, const Chess &C) {
	for (int i = 0; i < 8; ++i) {
		output << (i + 1) << ' ';
		for (int j = 0; j < 8; ++j) {
			if (C.board[i][j] != nullptr) {
				switch (C.board[i][j]->getType()) {
					case PAWN:   output << "P"; break;
					case ROOK:   output << "R"; break;
					case KNIGHT: output << "N"; break;
					case BISHOP: output << "B"; break;
					case QUEEN:  output << "Q"; break;
					case KING:   output << "K"; break;
				}
				if (C.board[i][j]->getColor() == WHITE) {
					output << "W ";
				} else {
					output << "B ";
				}
			} else {
				output << "** ";
			}
		}
		output << endl;
	}

	for (int i = 0; i < 8; ++i) {
		output << "  " << (char) ('a' + i);
	}
	output << endl;
	return output;
}