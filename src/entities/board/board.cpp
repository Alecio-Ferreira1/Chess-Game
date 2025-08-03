#include <ctype.h>
#include "board.h"

void Chess::Board::dealWithEnPassant(Pawn *&pawn, Vec2 to){
  delete boardMatrix[to.row - pawn->getOrientation()][to.col];
  boardMatrix[to.row - pawn->getOrientation()][to.col] = nullptr;
}

void Chess::Board::dealWithCastling(King *&king, Vec2 to){
  int rookRow = king->getColor() == Types::Color::Black ? 0 : 7;
  int toRemove, newCol;

  if(to.col == 2){
    toRemove = 0;
    newCol = 3;
  }

  else{
    toRemove = 7;
    newCol = 5;
  }

  boardMatrix[rookRow][newCol] = boardMatrix[rookRow][toRemove];
  boardMatrix[rookRow][newCol]->setPosition({rookRow, newCol});
  boardMatrix[rookRow][newCol]->moved();
  boardMatrix[rookRow][toRemove] = nullptr; 
}

void Chess::Board::dealWithPromotion(Pawn *&pawn, Types::Piece pieceType){
  const Vec2 pos = pawn->getPosition();
  const Types::Color color = pawn->getColor();
  Piece *piece = nullptr;

  switch(pieceType){
    case Types::Piece::Queen:
      piece = new Queen(color, pos);
    break;

    case Types::Piece::Rook:
      piece = new Rook(color, pos); 
    break;

    case Types::Piece::Knight:
      piece = new Knight(color, pos);
    break;

    case Types::Piece::Bishop:
      piece = new Bishop(color, pos);
    break;

    default: break;
  }

  boardMatrix[pos.row][pos.col] = piece;
  delete pawn;
  pawn = nullptr;
}