#include "board_interaction_controller.h"

Chess::Core::BoardInteractionController::BoardInteractionController(
  Game &game, 
  SelectionState &selectionState, 
  Draw::BoardRenderer &boardRenderer, 
  Draw::MoveIndicatorRenderer &moveIndicatorRenderer
) : 
    game(game), selectionState(selectionState), 
    boardRenderer(boardRenderer), moveIndicatorRenderer(moveIndicatorRenderer) { }

bool Chess::Core::BoardInteractionController::isEnemyPiece(Piece *piece) const{
  return (piece->getColor() == Types::Color::Black && game.getPlayerTurn() != 2) ||
         (piece->getColor() == Types::Color::White && game.getPlayerTurn() != 1);
}

void Chess::Core::BoardInteractionController::clearSelection(){
  boardRenderer.deSelect(selectionState.getfrom().value());
  selectionState.clear();
  moveIndicatorRenderer.clear();
}

void Chess::Core::BoardInteractionController::handleClick(sf::Vector2f mousePos){
  const sf::Vector2i coords = convertMousePosToBoardCoords(mousePos);
  const BoardMatrix boardMatrix = game.getBoard().getInfo();
  const bool isPieceSelected = boardMatrix[coords.y][coords.x] != nullptr;
  Player &player = game.getPlayers()[game.getPlayerTurn()];

  if(isPieceSelected){
    if(isEnemyPiece(boardMatrix[coords.y][coords.x]) && !selectionState.getfrom().has_value()) return;

    if(selectionState.getfrom().has_value()){
      sf::Vector2i previusSquare = selectionState.getfrom().value();

      if(!isEnemyPiece(boardMatrix[coords.y][coords.x])) clearSelection();

      if(previusSquare.x == coords.x && previusSquare.y == coords.y) return;
    }

    if(!selectionState.getfrom().has_value()){
      selectionState.select(coords);
      boardRenderer.select(coords);

      sf::Vector2i pieceSelectedCoords = selectionState.getfrom().value();
      Piece *pieceSelected = boardMatrix[pieceSelectedCoords.y][pieceSelectedCoords.x];

      std::vector<sf::Vector2i> moves = Vec2::vectorOfVec2ToVectorOfVector2i(
        game.filterMovesToAvoidInconsistencies(pieceSelected)
      );

      moveIndicatorRenderer.setMoves(moves);
      return;
    }
  }

  if(selectionState.getfrom().has_value()){
    selectionState.select(coords);

    sf::Vector2i from = selectionState.getfrom().value();
    sf::Vector2i to = selectionState.getTo().value();

    if(!game.invalidMove({from.y, from.x}, {to.y, to.x})){
      player.movePiece({from.y, from.x}, {to.y, to.x}, game.getBoard());
      game.changeTurn();
    }

    clearSelection();
  }
}

sf::Vector2i Chess::Core::BoardInteractionController::convertMousePosToBoardCoords(sf::Vector2f mousePos) {
  float squareSize = boardRenderer.getSquareSize();
  sf::Vector2f upperBounds = boardRenderer.getBoardPos();

  return {
    static_cast<int>((mousePos.x - upperBounds.x) / squareSize), 
    static_cast<int>((mousePos.y - upperBounds.y) / squareSize) 
  };
}