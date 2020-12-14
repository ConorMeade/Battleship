#include <conio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include "Piece.h"
#include "Node.h"
#include "Board.h"



#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77


using namespace std;


void printGameBoard(Node** nodeBoard){
    std::map<int, char> topRowMap;
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

    // int myArray[][4] = { {1,2,3,4}, {5,6,7,8} };
    // int width = 4, height = 2;

    // for (int i = 0; i < height; ++i)
    // {
    //     for (int j = 0; j < width; ++j)
    //     {
    //         std::cout << myArray[i][j] << ' ';
    //     }
    //     std::cout << std::endl;
    // }

    // Node** nodeBoard = board.createGameBoard();

    cout<< "     a b c d e f g h i j"<< endl;
    cout <<" +-----------------------+"<< endl;
    
    for(int i = 0; i < 10; ++i){
        if(i == 9){
            std::cout << i+1 << " |";
        }
        else{
            std::cout << " " << i + 1 << " |";
        }
        for(int j = 0; j < 10; ++j){
            std::cout << " " << nodeBoard[i][j].getState();
        }
        std::cout << std::endl;
    }

}

bool shipCollisionCheck(Node** nodeBoard, int dir, int length, int x, int y){
    // init board with 'O', if we loop and do not find an 'O', then this node is occupied by a ship
    bool collides = false;
    if(dir == KEY_UP){
        for(int i = y; i < y + length; i++){
            if(nodeBoard[x][i].getState() != 'O'){
                return true;
            }
        }
    }else if(dir == KEY_DOWN){
        for(int i = y; i > y - length; i--){
            if(nodeBoard[x][i].getState() != 'O'){
                return true;
            }
        }
    }else if(dir == KEY_LEFT){
        for(int i = x; i > x - length; i--){
            if(nodeBoard[i][y].getState() != 'O'){
                return true;
            }
        }
    }else if(dir == KEY_RIGHT){
        for(int i = x; i < x + length; i++){
            if(nodeBoard[i][y].getState() != 'O'){
                return true;
            }
        }
    }else{
        return true;
    }


    return collides;
}

bool edgeCheck(Node** nodeBoard, int dir, int pieceLength, int x, int y){
    // check if we collide with bounds of board or if we collide with another ship
    // handle bounds for x and y outside of (0-9)
    bool withinGrid = false;
    if(dir == KEY_UP){
        if (y + 1 >= pieceLength && shipCollisionCheck(nodeBoard, KEY_UP, pieceLength, x, y) /* && shipCollisionCheck() */)
        {
            withinGrid = true;
        }else{
            withinGrid = false;
        }
    }else if(dir == KEY_DOWN){
        if (10 - y >= pieceLength && shipCollisionCheck(nodeBoard, KEY_DOWN, pieceLength, x, y))
        {
            withinGrid = true;
        }else{
            withinGrid = false;
        }
    }else if(dir == KEY_RIGHT && shipCollisionCheck(nodeBoard, KEY_RIGHT, pieceLength, x, y)){
        if (10 - x >= pieceLength){
            withinGrid = true;
        }else{
            withinGrid = false;
        }
    }else if (dir == KEY_LEFT && shipCollisionCheck(nodeBoard, KEY_LEFT, pieceLength, x, y)){
        if (x + 1 >= pieceLength)
        {
            withinGrid = true;
        }else{
            withinGrid = false;
        }
    }else{
        withinGrid = false;
    }
    return withinGrid;
}

void printNodeValues(Node** nodeBoard){
    for(int i = 0; i < 10; ++i){
        for(int j = 0; j < 10; ++j){
            cout << "X: " << nodeBoard[i][j].getX() << " Y: " << nodeBoard[i][j].getY() << endl;
        }
    }
}

void placeShip(Node (**nodeBoard), Piece& gamePiece){
    std::map<char, int> xAxisMap;
    xAxisMap['a'] = 0;
    xAxisMap['b'] = 1;
    xAxisMap['c'] = 2;
    xAxisMap['d'] = 3;
    xAxisMap['e'] = 4;
    xAxisMap['f'] = 5;
    xAxisMap['g'] = 6;
    xAxisMap['h'] = 7;
    xAxisMap['i'] = 8;
    xAxisMap['j'] = 9;

    // set node's ship flag to true when we place
    int length = gamePiece.getPieceLength();
    int xPos;
    int yPos;
    int direction;
    bool validMove = false;
    std::cout << "Type X and Y coordinates for piece " << gamePiece.getPieceName() << ", use arrow keys to select direction. Length = " << gamePiece.getPieceLength() << "." << std::endl;
    std::cout << "Type X (character a-j): ";
    std::cin >> xPos;
    std::cout << "X is:" << xPos << std::endl;
    std::cout << "Type Y (number 1-10): ";
    std::cin >> yPos;
    std::cout << "Y is:" << yPos << std::endl;
    // rewrite switch statement, too bloated
    std::cout << "Use arrow keys (left, right, up, and down) to choose the direction for ship to face" << std::endl;
    while(!validMove){
        direction = getch();
        if(direction == KEY_UP){
            std::cout << "x:" << xPos << " y:" << yPos << std::endl;
            std::cout << endl << "Up" << endl; //key up
            validMove = edgeCheck(nodeBoard, KEY_UP, length, xPos - 1, yPos - 1);
            if(validMove){
                for(int i = yPos - 1; i < yPos + length - 1; i++){
                    nodeBoard[xPos - 1][i].setState(gamePiece.getStateLetter());
                }
            }else{
                std::cout << "collision check failed, try a different direction" << std::endl;
            }
        }else if(direction == KEY_DOWN){
            std::cout << "x:" << xPos << " y:" << yPos << std::endl;
            std::cout << endl << "Down" << endl; //key up
            validMove = edgeCheck(nodeBoard, KEY_DOWN, length, xPos - 1, yPos - 1);
            if(validMove){
                std::cout << "entered loop" << std::endl;
                for(int i = yPos - 1; i > yPos - length - 1; i--){
                    nodeBoard[xPos - 1][i].setState(gamePiece.getStateLetter());
                }
            }else{
                std::cout << "collision check failed, try a different direction" << std::endl;
            }
        }else if(direction == KEY_RIGHT){
            std::cout << "x:" << xPos << " y:" << yPos << std::endl;
            std::cout << endl << "Right" << endl; //key up
            validMove = edgeCheck(nodeBoard, KEY_RIGHT, length, xPos - 1, yPos - 1);
            if(validMove){
                for(int i = xPos - 1; i < xPos + length - 1; i++){
                    nodeBoard[i][yPos - 1].setState(gamePiece.getStateLetter());
                }
            }else{
                std::cout << "collision check failed, try a different direction" << std::endl;
            }
        }else if(direction == KEY_LEFT){
            std::cout << "x:" << xPos << " y:" << yPos << std::endl;
            std::cout << endl << "Left" << endl; //key up
            validMove = edgeCheck(nodeBoard, KEY_LEFT, length, xPos - 1, yPos - 1);
            if(validMove){
                for(int i = xPos - 1; i < xPos - length - 1; i++){
                    nodeBoard[i][yPos - 1].setState(gamePiece.getStateLetter());
                }
            }else{
                std::cout << "collision check failed, try a different direction" << std::endl;
            }
        }else{
            std::cout << "Not an arrow key, try again.";
            validMove = false;
        }

        // return newboard ?
    }
    std::cout << "out of loop" << std::endl;

}

void makeAttack(Node** nodeBoard, int *x, int *y) {
    // get node board
    // set node's 'hit' flag to true when attacking
}

int main(){
    Board playerOneBoard(1);
    Board playerTwoBoard(2);

    // collisionCheck()
    // printGameBoard(playerOneBoard);

    std::vector<Piece> g = playerOneBoard.getGamePieces();
    Node** nodeBoardOne = playerOneBoard.createGameBoard();
    Node** nodeBoardTwo = playerTwoBoard.createGameBoard();

    // printGameBoard(nodeBoardOne);

    for(Piece p: playerOneBoard.getGamePieces()){
        std::cout << "Before placing ship" << std::endl;
        printGameBoard(nodeBoardOne);
        placeShip(nodeBoardOne, p);
        std::cout << "After placing ship" << std::endl;
        printGameBoard(nodeBoardOne);
    }

    for(int i = 0; i < playerOneBoard.getBoardWidth(); ++i){
        delete [] nodeBoardOne[i];
        delete [] nodeBoardTwo[i];
    }

    delete [] nodeBoardOne;
    delete [] nodeBoardTwo;

    return 0;
}
