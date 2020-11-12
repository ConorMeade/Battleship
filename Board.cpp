#include "Node.h"
#include "Board.h"
#include <string>

// class Node(int x, int y);

Board::Board(int playerTF){
    boardHeight = 10;
    boardWidth = 10;
    player = playerTF;
    // need hash to set x values to letters
}

Board::~Board(){

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

void Board::setPlayer(){
    // when a player misses an attack, we swap players and we swap board states
    player = !player;
}


Node** Board::createGameBoard(){
    //2d array
    int area = boardHeight * boardWidth;
    Node** nodeBoard = 0;
    nodeBoard = new Node*[boardHeight];
    for(int i = 0; i < boardHeight; ++i){
        nodeBoard[i] = new Node[boardWidth];
        for(int j = 0; j < boardWidth; ++j){
            nodeBoard[i][j] = Node(i, j);
        }
    }
    return nodeBoard;
    // for(int i = 0; i < boardWidth; ++i){
    //     for(int j = 0; j < boardHeight; ++j){
    //         nodeBoard[i][j] = Node(i,j);
    //     }
    // }

    // return nodeBoard;
}

void Board::makeAttack(int *x, int *y) {

}


void Board::printGameBoard(const Board& board){

}
