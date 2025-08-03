#include "piece.h"

using namespace Chess;

Rook::Rook(Types::Color color, Vec2 position) : Piece(type, color, position) {
  this->type = Types::Piece::Rook;
}

std::vector<Vec2> Rook::getMoves(const BoardMatrix &boardMatrix){ 
  std::vector<Vec2> directions = {
    {goFoward, 0}, {0, goFoward}, {-goFoward, 0}, {0, -goFoward}
  };

  return Utils::genSlidingMoves(position, boardMatrix, directions);
}