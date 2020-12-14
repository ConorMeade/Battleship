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

    cout<< "     a b c d e f g h i j"<< endl;
    cout <<" +-----------------------+"<< endl;
    
    for(int i = 0; i < board.getBoardHeight(); ++i){
        if(i == 9){
            std::cout << i+1 << " |";
        }
        else{
            std::cout << " " << i + 1 << " |";
        }
        // << "(" << nodeBoard[i][0].getX() << ", " << nodeBoard[i][0].getY() << ")";
        for(int j = 0; j < board.getBoardWidth(); ++j){
            // std::cout << " (" << nodeBoard[i][j].getX() << ", " << nodeBoard[i][j].getY() << ")" << ' ';
            std::cout << " " << nodeBoard[i][j].getState();
            // std::cout << "(" << nodeBoard[i][j].getX() << ", " << nodeBoard[i][j].getY() << ")" << ' ';
        }
        std::cout << std::endl;
    }

}

bool collisionCheck(int dir, int pieceLength, int x, int y){
    // check if we collide with bounds of board or if we collide with another ship
    // handle bounds for x and y outside of (0-9)
    bool withinGrid = false;
    if(dir == KEY_UP){
        if (y + 1 >= pieceLength)
        {
            withinGrid = true;
        }else{
            withinGrid = false;
        }
    }else if(dir == KEY_DOWN){
        if (10 - y >= pieceLength)
        {
            withinGrid = true;
        }else{
            withinGrid = false;
        }
    }else if(dir == KEY_RIGHT){
        if (10 - x >= pieceLength){
            withinGrid = true;
        }else{
            withinGrid = false;
        }
    }else if (dir == KEY_LEFT){
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

void placeShip(Node** nodeBoard, Piece& gamePiece){
    // set node's ship flag to true when we place
    std::set<std::string> directions = {"left", "right", "up", "down"};
    int length = gamePiece.getPieceLength();
    int xPos;
    int yPos;
    int direction;
    bool validMove = false;
    std::cout << "Type X and Y coordinates for piece " << gamePiece.getPieceName() << ", use arrow keys to select direction. Length = " << gamePiece.getPieceLength() << "." << std::endl;
    std::cout << "Type X: ";
    std::cin >> xPos;
    std::cout << "X is:" << xPos << std::endl;
    std::cout << "Type Y: ";
    std::cin >> yPos;
    std::cout << "Y is:" << yPos << std::endl;
    while(!validMove)
    {
        direction = 0;

        std::cout << "Use arrow keys (left, right, up, and down) to choose the direction for ship to face" << std::endl;
        switch((direction=getch())) {
        case KEY_UP:
            std::cout << "x:" << xPos << " y:" << yPos << std::endl;
            std::cout << endl << "Up" << endl; //key up
            direction=KEY_UP;
            validMove = collisionCheck(direction, gamePiece.getPieceLength(), xPos, yPos);
            if(!validMove){
                std::cout << "invalid move, try a different direction";
            }
            break;
        case KEY_DOWN:
            std::cout << "x:" << xPos << " y:" << yPos << std::endl;
            std::cout << endl << "Down" << endl;   // key down
            direction=KEY_DOWN;
            validMove = collisionCheck(direction, gamePiece.getPieceLength(), xPos, yPos);
            if(!validMove){
                std::cout << "invalid move, try a different direction";
            }
            break;
        case KEY_LEFT:
            std::cout << "x:" << xPos << " y:" << yPos << std::endl;
            std::cout << endl << "Left" << endl;  // key left
            direction=KEY_LEFT;
            validMove = collisionCheck(direction, gamePiece.getPieceLength(), xPos, yPos);
            if(!validMove){
                std::cout << "invalid move, try a different direction";
            }
            break;
        case KEY_RIGHT:
            std::cout << "x:" << xPos << " y:" << yPos << std::endl;
            std::cout << endl << "Right" << endl;  // key right
            direction=KEY_RIGHT;
            validMove = collisionCheck(direction, gamePiece.getPieceLength(), xPos, yPos);
            if(!validMove){
                std::cout << "invalid move, try a different direction";
            }
            break;
        default:
            // std::cout << endl << "null" << endl;  // not arrow
            validMove = false;
            break;
        }
    }
}

void makeAttack(Node** nodeBoard, int *x, int *y) {
    // get node board
    // set node's 'hit' flag to true when attacking
}

int main(){
    Board playerOneBoard(1);
    Board playerTwoBoard(2);

    // collisionCheck()
    printGameBoard(playerOneBoard);

    std::vector<Piece> g = playerOneBoard.getGamePieces();
    Node** nodeBoardOne = playerOneBoard.createGameBoard();
    Node** nodeBoardTwo = playerTwoBoard.createGameBoard();

    // for(Piece p: playerOneBoard.getGamePieces()){
    //     printGameBoard(playerOneBoard);
    //     placeShip(nodeBoardOne, p);
    // }

    for(int i = 0; i < playerOneBoard.getBoardWidth(); ++i){
        delete [] nodeBoardOne[i];
        delete [] nodeBoardTwo[i];
    }

    delete [] nodeBoardOne;
    delete [] nodeBoardTwo;

    return 0;
}
