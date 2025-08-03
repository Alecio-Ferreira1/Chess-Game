#pragma once
#include "..\entities/board/board.h"
#include "..\entities/player/player.h"
#include "..\entities/pieces/piece.h"
#include "../utils/types.h"

#include <tuple>
#include <vector>

namespace Chess{
  class Game{    //SUGEST FOR THINK LATER :::::: STORE KING POSITIONS, TO DECREASE CALCULATIONS IN VERIFY STALEMATE
    private:
    Board board;
    Player players[2];
    short int playerTurn = 1;
    bool running = false; 
    Types::Status status = Types::Status::Normal;

    void generatePieces();
    void removePieces();

    public:
    Game();
    Board &getBoard() { return board; }
    Player *getPlayers() { return players; }
    Types::Status getStatus() const { return status; }
    short int getPlayerTurn () { return playerTurn; }
    bool isRunning() const { return running; }
    void start(); 
    void end();
    bool invalidMove(Vec2 from, Vec2 to);
    void updateStatus();
    void changeTurn();
    bool check();
    bool checkmate();
    bool stalemate();
    bool finished();
    bool verifyStalemate();
    std::vector<Vec2> filterMovesToAvoidInconsistencies(Piece *pieceSelected);
  };
}