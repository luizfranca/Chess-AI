#include "piece.h"

Color Piece::getColor() {
	return color;
}

Type Piece::getType() {
	return type;
}

Pawn::Pawn(Color color) {
	this->color = color;
	this->type = PAWN;
}

bool Pawn::move(int x, int y) {
	return true;
}

Rook::Rook(Color color) {
	this->color = color;
	this->type = ROOK;
}

bool Rook::move(int x, int y) {
	return true;
}

Knight::Knight(Color color) {
	this->color = color;
	this->type = KNIGHT;
}

bool Knight::move(int x, int y) {
	return true;
}

Bishop::Bishop(Color color) {
	this->color = color;
	this->type = BISHOP;
}

bool Bishop::move(int x, int y) {
	return true;
}

Queen::Queen(Color color) {
	this->color = color;
	this->type = QUEEN;
}

bool Queen::move(int x, int y) {
	return true;
}

King::King(Color color) {
	this->color = color;
	this->type = KING;
}

bool King::move(int x, int y) {
	return true;
}