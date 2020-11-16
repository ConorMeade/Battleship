#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "Node.h"
#include "Board.h"
#include "Piece.h"


using namespace std;


// void makeAttack(std::string attackCords){

// }
void printGameBoard(Board& board){
     std::map<int, char> topRowMap;
    topRowMap[1] = 'A';
    topRowMap[2] = 'B';
    topRowMap[3] = 'C';
    topRowMap[4] = 'D';
    topRowMap[5] = 'E';
    topRowMap[6] = 'F';
    topRowMap[7] = 'G';
    topRowMap[8] = 'H';
    topRowMap[9] = 'I';
    topRowMap[10] = 'J';

    int myArray[][4] = { {1,2,3,4}, {5,6,7,8} };
    int width = 4, height = 2;

    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            std::cout << myArray[i][j] << ' ';
        }
        std::cout << std::endl;
    }

    Node** nodeBoard = board.createGameBoard();

    for(int i = 0; i < board.getBoardHeight(); ++i){
        for(int j = 0; j < board.getBoardWidth(); ++j){
            std::cout << "(" << nodeBoard[i][j].getX() << ", " << nodeBoard[i][j].getY() << ")" << ' ';
        }
        std::cout << std::endl;
    }

}

void placeShip(Board& gameBoard, Piece& gamePiece){

}

int main(){
    vector<int> intVector;

    intVector.push_back(1);
    intVector.push_back(2);

    for(int &a : intVector){
        cout << a << endl;
    }

    Node testNode(0, 8);

    cout << testNode.getX() << endl;
    cout << testNode.getY() << endl;
    Board playerOneBoard(1);
    Board playerTwoBoard(2);


    Node** nodeBoardOne = playerOneBoard.createGameBoard();
    Node** nodeBoardTwo = playerTwoBoard.createGameBoard();

    printGameBoard(playerOneBoard);


    // for(int i = 0; i < playerOneBoard.getBoardHeight(); ++i){
    //     for(int j = 0; j < playerOneBoard.getBoardWidth(); ++j){
    //         cout << "X: " << nodeBoardOne[i][j].getX() << " Y: " << nodeBoardOne[i][j].getY() << endl;
    //     }
    // }

    for(int i = 0; i < playerOneBoard.getBoardWidth(); ++i){
        delete [] nodeBoardOne[i];
        delete [] nodeBoardTwo[i];
    }

    delete [] nodeBoardOne;
    delete [] nodeBoardTwo;

    cout << "Hello World" << endl;
    return 0;
}
