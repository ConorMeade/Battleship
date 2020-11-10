#include "Board.h"
#include "Node.h"
#include <string>


Board::Board(bool playerNum){
    boardHeight = 10;
    boardWidth = 10;
    // false indicates player 1, true indicates player 2
    player = playerNum;
    // gameBoard = new int[boardHeight, boardWidth]
}


int Board::getBoardWidth(){
    return boardWidth;
}

int Board::getBoardHeight(){
    return boardWidth;
}

std::string Board::getPlayer(){
    if(!player){
        return "Player #1";
    }
    return "Player #2";
}

int** Board::createGameBoard(){
    //2d array
    int** array2d = 0;
}


void Baord::printGameBoard(){

}
