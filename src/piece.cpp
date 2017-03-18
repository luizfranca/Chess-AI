#include <cstdlib>
#include "piece.h"

using namespace std;

Color Piece::getColor() {
	return color;
}

Type Piece::getType() {
	return type;
}

bool Piece::checkPath(int fromX, int fromY, int toX, int toY, Piece *board[8][8]) {
	int x = fromX;
	int y = fromY;
	int xFactor = fromX < toX ? 1 : -1;
	int yFactor = fromY < toY ? 1 : -1;

	while (x != toX - xFactor || y != toY - yFactor) {
		if (board[x][y] == nullptr) {
			return false;
		}
		if (fromX != toX) {
			x += xFactor;
		}
		if (fromY != toY) {
			y += yFactor;
		}
	}

	return true;
}

Pawn::Pawn(Color color) {
	this->color = color;
	this->type = PAWN;
}

bool Pawn::isValid(int fromX, int fromY, int toX, int toY, Piece *board[8][8]) {

	return true;
}

Rook::Rook(Color color) {
	this->color = color;
	this->type = ROOK;
}

bool Rook::isValid(int fromX, int fromY, int toX, int toY, Piece *board[8][8]) {
	if (fromX != toX && fromY != toY) {
		return false;
	} else if (board[toX][toY] != nullptr && board[toX][toY]->getColor() == this->color) {
		return false;
	} else if (this->checkPath(fromX, fromY, toX, toY, board)) {
		return true;
	}

	return false;
}

Knight::Knight(Color color) {
	this->color = color;
	this->type = KNIGHT;
}

bool Knight::isValid(int fromX, int fromY, int toX, int toY, Piece *board[8][8]) {
	return true;
}

Bishop::Bishop(Color color) {
	this->color = color;
	this->type = BISHOP;
}

bool Bishop::isValid(int fromX, int fromY, int toX, int toY, Piece *board[8][8]) {
	if (abs(fromX - toX) != abs(fromY - toY)) {
		return false;
	} else if (board[toX][toY] != nullptr && board[toX][toY]->getColor() == this->color) {
		return false;
	} else if (this->checkPath(fromX, fromY, toX, toY, board)) {
		return true;
	}

	return false;
}

Queen::Queen(Color color) {
	this->color = color;
	this->type = QUEEN;
}

bool Queen::isValid(int fromX, int fromY, int toX, int toY, Piece *board[8][8]) {
	return true;
}

King::King(Color color) {
	this->color = color;
	this->type = KING;
}

bool King::isValid(int fromX, int fromY, int toX, int toY, Piece *board[8][8]) {
	return true;
}