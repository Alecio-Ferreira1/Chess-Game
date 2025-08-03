#pragma once 
#include <SFML/Graphics.hpp>

namespace Chess{
  class Textures{
    private:
    sf::Texture whitePawn, whiteKnight, whiteRook;
    sf::Texture whiteBishop, whiteQueen, whiteKing;
    sf::Texture blackPawn, blackKnight, blackRook;
    sf::Texture blackBishop, blackQueen, blackKing;
    sf::Font font;

    void loadPieces();
    void loadFonts();

    public:
    Textures();
    sf::Sprite whitePawnSprite();
    sf::Sprite whiteKnightSprite();
    sf::Sprite whiteRookSprite();
    sf::Sprite whiteBishopSprite(); 
    sf::Sprite whiteQueenSprite();
    sf::Sprite whiteKingSprite();
    sf::Sprite blackPawnSprite();
    sf::Sprite blackKnightSprite(); 
    sf::Sprite blackRookSprite();
    sf::Sprite blackBishopSprite();
    sf::Sprite blackQueenSprite();
    sf::Sprite blackKingSprite();
    sf::Font& getFont();
  };

  extern Textures allTextures;
}