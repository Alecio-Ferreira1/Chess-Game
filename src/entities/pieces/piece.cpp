#include "piece.h"

Chess::Piece::Piece(Types::Piece type, Types::Color color, Vec2 position){
  this->type = type;
  this->color = color;
  this->position = position;
  goFoward = color == Types::Color::Black ? 1 : -1;
}

//TODO:  DON'T FORGET TO GET BACK HERE
// bool Chess::Piece::isPinned(const BoardMatrix &boardMatrix){
//   // std::vector<Vec2> moves = getMoves(boardMatrix);

//   // this->pinned = Utils::momentaniumCheck(
//   //   moves.empty() ? std::tuple<Vec2, Vec2>({-1, -1}, {-1, -1}) : 
//   //   std::tuple<Vec2, Vec2>(position, moves[0]), boardMatrix
//   // );

//   // return pinned;
// } 