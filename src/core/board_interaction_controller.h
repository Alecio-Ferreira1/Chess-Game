#pragma once

#include "../game/game.h"
#include "../draw/draw.h"
#include "selection_state.h"


namespace Chess::Core{
  class BoardInteractionController{
    private:
    Game &game;
    SelectionState &selectionState; 
    Draw::BoardRenderer &boardRenderer;
    Draw::MoveIndicatorRenderer &moveIndicatorRenderer;

    bool isEnemyPiece(Piece *piece) const;
    void clearSelection();
    sf::Vector2i convertMousePosToBoardCoords(sf::Vector2f mousePos);


    public:
    BoardInteractionController(Game &game, 
                               SelectionState &selectionState, 
                               Draw::BoardRenderer &boardRenderer, 
                               Draw::MoveIndicatorRenderer &moveIndicatorRenderer
    );

    void handleClick(sf::Vector2f mousePos);
  };
}