#include "piece.h"

using namespace Chess;

Knight::Knight(Types::Color color, Vec2 position) : Piece(type, color, position) {
  this->type = Types::Piece::Knight;
}

std::vector<Vec2> Knight::getMoves(const BoardMatrix &boardMatrix){
  const Vec2 allMoves[8] = {
    {2 * goFoward, goFoward}, {2 * goFoward, -goFoward}, 
    {goFoward, 2 * goFoward}, {goFoward, -2 * goFoward},
    {-goFoward, 2 * goFoward}, {-goFoward, -2 * goFoward},
    {-2 * goFoward, goFoward}, {-2 * goFoward, -goFoward}
  };

  std::vector<Vec2> moves;

  for(const Vec2& move : allMoves){
    if(
      Utils::coordsInsideBounds({position.row + move.row, position.col + move.col}) && 
      ((boardMatrix[position.row + move.row][position.col + move.col] == nullptr) ||
      boardMatrix[position.row + move.row][position.col + move.col]->getColor() != color)      //// PIECE ENEMY FOUND!!!!
    ){
      moves.push_back({position.row + move.row, position.col + move.col});
    }
  }

  return moves;
}