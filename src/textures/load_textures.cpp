#include "load_textures.h"

namespace Chess{
  Textures::Textures(){
    loadPieces();
    loadFonts();  
  }

  void Textures::loadPieces(){
    whitePawn = sf::Texture("assets/pieces/white_pawn.png");
    whiteKnight = sf::Texture("assets/pieces/white_knight.png");
    whiteBishop = sf::Texture("assets/pieces/white_bishop.png");
    whiteRook = sf::Texture("assets/pieces/white_rook.png");
    whiteQueen = sf::Texture("assets/pieces/white_queen.png");
    whiteKing = sf::Texture("assets/pieces/white_king.png");

    blackPawn = sf::Texture("assets/pieces/black_pawn.png");
    blackKnight = sf::Texture("assets/pieces/black_knight.png");
    blackBishop = sf::Texture("assets/pieces/black_bishop.png");
    blackRook = sf::Texture("assets/pieces/black_rook.png");
    blackQueen = sf::Texture("assets/pieces/black_queen.png");
    blackKing = sf::Texture("assets/pieces/black_king.png");
  }

  void Textures::loadFonts(){
    font = sf::Font("assets/fonts/arial.ttf");
  }

  sf::Font& Textures::getFont() { return font; }
  sf::Sprite Textures::whitePawnSprite() { return sf::Sprite(whitePawn); }
  sf::Sprite Textures::whiteKnightSprite() { return sf::Sprite(whiteKnight); }
  sf::Sprite Textures::whiteRookSprite() { return sf::Sprite(whiteRook); }
  sf::Sprite Textures::whiteBishopSprite() { return sf::Sprite(whiteBishop); } 
  sf::Sprite Textures::whiteQueenSprite() { return sf::Sprite(whiteQueen); }
  sf::Sprite Textures::whiteKingSprite() { return sf::Sprite(whiteKing); }
  sf::Sprite Textures::blackPawnSprite() { return sf::Sprite(blackPawn); }
  sf::Sprite Textures::blackKnightSprite() { return sf::Sprite(blackKnight); } 
  sf::Sprite Textures::blackRookSprite() { return sf::Sprite(blackRook); }
  sf::Sprite Textures::blackBishopSprite() { return sf::Sprite(blackBishop); }
  sf::Sprite Textures::blackQueenSprite() { return sf::Sprite(blackQueen); }
  sf::Sprite Textures::blackKingSprite() { return sf::Sprite(blackKing); }
 
  Textures allTextures;
}