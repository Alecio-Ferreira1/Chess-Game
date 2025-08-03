#pragma once
#include <vector>
#include <list>
#include <SFML/System/Vector2.hpp>

#include "types.h"

struct Vec2{ 
  int row;
  int col;
  
  static sf::Vector2i toVector2i(Vec2 coords); 
  static std::vector<sf::Vector2i> vectorOfVec2ToVectorOfVector2i(std::vector<Vec2> vector);
};

namespace Chess::Utils{
  extern std::list<std::tuple<Vec2, Vec2>> plays;

  inline bool coordsInsideBounds(Vec2 coord){
    return coord.row >= 0 && coord.row <= 7 && coord.col >=0 && coord.col <= 7; 
  }

  std::vector<Vec2> genSlidingMoves(
    Vec2 pos, const BoardMatrix &boardMatrix, std::vector<Vec2> directions
  );

  bool momentaniumCheck(std::tuple<Vec2, Vec2> move, Chess::BoardMatrix BoardMatrix);
}   