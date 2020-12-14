#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "Piece.h"
#include "Node.h"
#include "Board.h"


Board::Board(int playerTF){
    boardHeight = 10;
    boardWidth = 10;
    player = playerTF;
    topRowMap[1] = 'a';
    topRowMap[2] = 'b';
    topRowMap[3] = 'c';
    topRowMap[4] = 'd';
    topRowMap[5] = 'e';
    topRowMap[6] = 'f';
    topRowMap[7] = 'g';
    topRowMap[8] = 'h';
    topRowMap[9] = 'i';
    topRowMap[10] = 'j';
    gamePieces = {
        Piece(1, "Carrier", 5, false, 'C'),
        Piece(2, "Battleship", 4, false, 'B'),
        Piece(3, "Destroyer", 3, false, 'D'),
        Piece(4, "Submarine", 3, false, 'S'),
        Piece(5, "Patrol Boat", 2, false, 'P')
    };
}

Board::~Board(){

}

const std::vector<Piece>& Board::getGamePieces(){
    return gamePieces;
}

const std::unordered_map<int, char>& Board::getTopRowMap(){
    return topRowMap;
}

int Board::getBoardWidth(){
    return boardWidth;
}

int Board::getBoardHeight(){
    return boardWidth;
}

std::string Board::getPlayer(){
    if(player == 1){
        return "Player #1";
    }
    return "Player #2";
}

void Board::setPlayer(int newID){
    // when a player misses an attack, we swap players and we swap board states
    player = newID;
}


Node** Board::createGameBoard(){
    //2d array
    int area = boardHeight * boardWidth;
    Node** nodeBoard = 0;
    nodeBoard = new Node*[boardHeight];
    for(int i = 0; i < boardHeight; ++i){
        // default constructor for Node class
        nodeBoard[i] = new Node[boardWidth];
        for(int j = 0; j < boardWidth; ++j){
            nodeBoard[i][j] = Node(j, i);
        }
    }
    return nodeBoard;
}

void Board::makeAttack(int *x, int *y) {

}