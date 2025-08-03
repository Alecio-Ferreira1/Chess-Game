#pragma once

#include <SFML/Graphics.hpp>
#include "../game/game.h"
#include "../config/config.h"
#include "../draw/draw.h"
#include "board_interaction_controller.h"

namespace Chess::Core{
  class GameApp{
    private:
    sf::RenderWindow window;
    Game game;
    Draw::BoardRenderer boardRenderer;
    Draw::PieceRenderer pieceRenderer;
    Draw::MoveIndicatorRenderer moveIndicatorRenderer;
    Core::SelectionState selectionState;
    Core::BoardInteractionController interactionController;

    void handleEvents();
    void getInput(std::optional<sf::Event>& event);
    void render();
    void renderPieces();
    bool boardClicked(sf::Vector2f mousePos);

    public:
    GameApp();
    void run();
  };
}