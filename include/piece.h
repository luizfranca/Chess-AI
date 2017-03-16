class Piece
{
public:
	virtual bool move(int x, int y) = 0;
};

class Pawn : public Piece {
public:
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