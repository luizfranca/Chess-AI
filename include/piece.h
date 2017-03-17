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
public:
	Rook(Color color);
	bool move(int x, int y);

};

class Knight : public Piece {
public:
	Knight(Color color);
	bool move(int x, int y);

};

class Bishop : public Piece {
public:
	Bishop(Color color);
	bool move(int x, int y);


};

class Queen : public Piece {
public:
	Queen(Color color);
	bool move(int x, int y);

};

class King : public Piece {
public:
	King(Color color);
	bool move(int x, int y);

};

#endif