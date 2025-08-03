#include "selection_state.h"

void Chess::Core::SelectionState::select(sf::Vector2i tile){
  if(!from.has_value()) 
    from = tile;
  
  else if(!to.has_value()) 
    to = tile;
  
  else{
    from = tile;
    to.reset();
  }
}

void Chess::Core::SelectionState::clear(){
  from.reset();
  to.reset();
}