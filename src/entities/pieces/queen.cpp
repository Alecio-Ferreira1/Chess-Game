#include "piece.h"

using namespace Chess;

Queen::Queen(Types::Color color, Vec2 position) : Piece(type, color, position) {
  this->type = Types::Piece::Queen;
}

std::vector<Vec2> Queen::getMoves(const BoardMatrix &boardMatrix){
  std::vector<Vec2> directions = {
    {goFoward, goFoward}, {goFoward, -goFoward},
    {-goFoward, goFoward}, {-goFoward, -goFoward},
    {goFoward, 0}, {0, goFoward},
    {-goFoward, 0}, {0, -goFoward}
  };

  return Utils::genSlidingMoves(position, boardMatrix, directions);
}