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