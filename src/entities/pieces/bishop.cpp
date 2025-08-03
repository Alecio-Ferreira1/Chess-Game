#include "piece.h"

using namespace Chess;

Bishop::Bishop(Types::Color color, Vec2 position) : Piece(type, color, position) {
  this->type = Types::Piece::Bishop;
}

std::vector<Vec2> Bishop::getMoves(const BoardMatrix &boardMatrix){
  std::vector<Vec2> directions = {
    {goFoward, goFoward}, {goFoward, -goFoward},
    {-goFoward, goFoward}, {-goFoward, -goFoward}
  };

  return Utils::genSlidingMoves(position, boardMatrix, directions);
}