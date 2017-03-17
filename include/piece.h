#include "utils.h"

#ifndef PIECE_H
#define PIECE_H

class Piece
{
public:
	virtual bool isValid(int fromX, int fromY, int toX, int toY, Piece *board[8][8]) = 0;
	Color getColor();
	Type getType();
	bool checkPath(int fromX, int fromY, int toX, int toY, Piece *board[8][8]);

protected:
	Color color;
	Type type;
};

class Pawn : public Piece {
public:
	Pawn(Color color);
	bool isValid(int fromX, int fromY, int toX, int toY, Piece *board[8][8]);

};

class Rook : public Piece {
public:
	Rook(Color color);
	bool isValid(int fromX, int fromY, int toX, int toY, Piece *board[8][8]);

};

class Knight : public Piece {
public:
	Knight(Color color);
	bool isValid(int fromX, int fromY, int toX, int toY, Piece *board[8][8]);

};

class Bishop : public Piece {
public:
	Bishop(Color color);
	bool isValid(int fromX, int fromY, int toX, int toY, Piece *board[8][8]);


};

class Queen : public Piece {
public:
	Queen(Color color);
	bool isValid(int fromX, int fromY, int toX, int toY, Piece *board[8][8]);

};

class King : public Piece {
public:
	King(Color color);
	bool isValid(int fromX, int fromY, int toX, int toY, Piece *board[8][8]);
};

#endif