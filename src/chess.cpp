#include "chess.h"

using namespace std;

Chess::Chess() {
	for (int i = 0; i < 8; ++i)
	{
		board[1][i] = make_unique<Pawn>(BLACK);
		board[6][i] = make_unique<Pawn>(WHITE);
		if (i == 0 || i == 7) {
			board[0][i] = make_unique<Rook>(BLACK);
			board[7][i] = make_unique<Rook>(WHITE);
		} else if (i == 1 || i == 6) {
			board[0][i] = make_unique<Knight>(BLACK);
			board[7][i] = make_unique<Knight>(WHITE);
		} else if (i == 2 || i == 5) {
			board[0][i] = make_unique<Bishop>(BLACK);
			board[7][i] = make_unique<Bishop>(WHITE);
		} else if (i == 3) {
			board[0][i] = make_unique<Queen>(BLACK);
			board[7][i] = make_unique<Queen>(WHITE);
		} else {
			board[0][i] = make_unique<King>(BLACK);
			board[7][i] = make_unique<King>(WHITE);
		}
		
	}
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