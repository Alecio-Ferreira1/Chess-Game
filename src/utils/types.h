#pragma once
#include <array>

namespace Chess::Types{
  enum class Piece { None, Rook, Knight, Bishop, Queen, King, Pawn };
  enum class Color { None, White, Black };
  enum class Status { Normal, Check, Stalemate, CheckMate };
}

namespace Chess{
  class Piece;

  using BoardMatrix = std::array<std::array<Piece *, 8>, 8>;
}