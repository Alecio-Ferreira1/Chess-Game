#pragma once 

#include <SFML/Graphics.hpp>
#include <optional>

namespace Chess::Core{
  class SelectionState{
    private:
    std::optional<sf::Vector2i> from;
    std::optional<sf::Vector2i> to;

    public:
    std::optional<sf::Vector2i> getfrom() { return from; }
    std::optional<sf::Vector2i> getTo() { return to; }
    void select(sf::Vector2i tile);
    void clear();
  };
}