#include "chess.h"

using namespace std;

Chess::Chess() {
	for (int i = 0; i < 8; ++i)
	{
		board[1][i] = make_unique<Pawn>(BLACK);
		board[6][i] = make_unique<Pawn>(WHITE);
	}
}

ostream &operator<<( ostream &output, const Chess &C) {
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (C.board[i][j] != NULL) {
				switch (C.board[i][j]->getType()) {
					case PAWN: output << "P ";
						break;
					case ROOK: output << "R ";
						break;
					case KNIGHT: output << "N ";
						break;
					case BISHOP: output << "B ";
						break;
					case QUEEN: output << "Q ";
						break;
					case KING: output << "K ";
						break;
				}
			} else {
				output << "* ";
			}
		}
		output << endl;
	}
	return output;
}