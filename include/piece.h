#include "utils.h"

#ifndef PIECE_H
#define PIECE_H

class Piece
{
public:
	virtual bool move(int x, int y) = 0;
	Color getColor();
	Type getType();

protected:
	Color color;
	Type type;
};

class Pawn : public Piece {
public:
	Pawn(Color color);
	bool move(int x, int y);

};

class Rook : public Piece {


};

class Knight : public Piece {


};

class Bishop : public Piece {


};

class Queen : public Piece {


};

class King : public Piece {


};

#endif