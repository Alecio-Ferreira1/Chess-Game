#pragma once
#include <array>
#include "../pieces/piece.h"
#include "../../utils/types.h"

namespace Chess{
  class Board{
    private:
    BoardMatrix boardMatrix = {};  

    public:
    Board() = default;
    ~Board() = default;
    BoardMatrix &getInfo() { return boardMatrix; }
    void dealWithEnPassant(Pawn *&pawn, Vec2 to);
    void dealWithCastling(King *&king, Vec2 to);
    void dealWithPromotion(Pawn *&pawn, Types::Piece pieceType = Types::Piece::Queen);
  };
}