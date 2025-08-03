#include "game_app.h"

#include <iostream>  //FOR DEBUG ONLY

Chess::Core::GameApp::GameApp() : 
 interactionController(game, selectionState, boardRenderer, moveIndicatorRenderer
){
  window = sf::RenderWindow(
    sf::VideoMode({Config::windowWidth, Config::windowWidth}), 
    Config::windowTitle, sf::Style::Default
  );

  window.setVerticalSyncEnabled(true);
  game.start();
}

void Chess::Core::GameApp::run(){ 
  while(window.isOpen()){
    handleEvents();
    game.updateStatus();

    if(game.check()) //SEND A ALERT LATER
      std::cout<<"CHECK!\n";

    if(game.finished()){
      render();
      break;
    }

    render();
  }

  if(game.checkmate())         //////////FOR DEBUG ONLY (IOSTREAM)   ----> CHANGE TO A DIALOG WINDOW
    std::cout<<"\nCHECKMATE!!!\n";

  if(game.stalemate())         //////////FOR DEBUG ONLY (IOSTREAM)
    std::cout<<"\nSTALEMATE!!!\n";

  std::cout<<"\nJOGO FINALIZADO!\n";
  std::cin.get();
  window.close();

  game.end();
}

void Chess::Core::GameApp::handleEvents(){
  while(std::optional<sf::Event> event = window.pollEvent()){
    if(event->is<sf::Event::Closed>())
      window.close();

    getInput(event);
  }
}

void Chess::Core::GameApp::getInput(std::optional<sf::Event>& event){
  if(event->is<sf::Event::KeyPressed>()){
    auto key = event->getIf<sf::Event::KeyPressed>();

    if(key->code == sf::Keyboard::Key::Escape){
      window.close();
    }
  }

  if(event->is<sf::Event::MouseButtonPressed>()){
    auto mouseEvent = event->getIf<sf::Event::MouseButtonPressed>();

    if(mouseEvent->button == sf::Mouse::Button::Left){
      sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
      sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);
      
      if(boardClicked(worldPos)){
        interactionController.handleClick(worldPos);
      }
    }
  }
}

void Chess::Core::GameApp::render(){
  unsigned int w = window.getSize().x;
  unsigned int h = window.getSize().y;

  sf::Vector2f center = {
    (w / 2) - 4 * boardRenderer.getSquareSize(), 
    (h / 2) - 4 * boardRenderer.getSquareSize()
  };

  sf::View view(sf::FloatRect{
    {0.f, 0.f}, 
    {static_cast<float>(w), 
     static_cast<float>(h)}
  });
  
  window.clear(sf::Color::White);
  boardRenderer.draw(window, center);
  renderPieces();
  moveIndicatorRenderer.draw(window, boardRenderer.getSquareSize(), boardRenderer.getBoardPos());
  window.setView(view);
  window.display();
}

void Chess::Core::GameApp::renderPieces(){
  BoardMatrix boardMatrix = game.getBoard().getInfo();

  for(int i = 0; i < 8; ++i){
    for(int j = 0; j < 8; ++j){
      if(boardMatrix[i][j] != nullptr){
        pieceRenderer.draw(window, boardMatrix[i][j], boardRenderer.getSquareSize(), boardRenderer.getBoardPos());
      }
    }
  }
}

bool Chess::Core::GameApp::boardClicked(sf::Vector2f mousePos){
  float squareSize = boardRenderer.getSquareSize();
  sf::Vector2f upperBounds = boardRenderer.getBoardPos();

  sf::Vector2f lowerBounds = {
    8 * squareSize + upperBounds.x, 
    8 * squareSize + upperBounds.y
  };

  return (mousePos.x >= upperBounds.x && mousePos.x <= lowerBounds.x &&
          mousePos.y >= upperBounds.y && mousePos.y <= lowerBounds.y);
}