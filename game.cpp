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
    
    for(int i = 0; i < board.getBoardHeight(); ++i){
        for(int j = 0; j < board.getBoardWidth(); ++j){
            std::cout << "(" << nodeBoard[i][j].getX() << ", " << nodeBoard[i][j].getY() << ")" << ' ';
        }
        std::cout << std::endl;
    }

}

bool collisionCheck(int dir, int pieceLength, int x, int y){
    // check if we collide with bounds of board or if we collide with another ship
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
    std::set<std::string> directions = {"left", "right", "up", "down"};
    int length = gamePiece.getPieceLength();
    int x;
    int y;
    int direction;
    std::cout << "Type X: ";
    std::cin >> x;
    std::cout << "Type Y: ";
    std::cin >> y;
    std::cout << "Use arrow keys to indicate direction you want " << gamePiece.getPieceName() << " to face, piece length = " << gamePiece.getPieceLength() << ".";  
    bool validMove = false;
    int placedShips = 0;
    while(!validMove && placedShips < 5)
    {
        direction = 0;

        switch((direction=getch())) {
        case KEY_UP:
            std::cout << endl << "Up" << endl;//key up
            direction=KEY_UP;
            validMove = collisionCheck(direction, gamePiece.getPieceLength(), x, y);
            break;
        case KEY_DOWN:
            std::cout << endl << "Down" << endl;   // key down
            direction=KEY_DOWN;
            validMove = collisionCheck(direction, gamePiece.getPieceLength(), x, y);
            break;
        case KEY_LEFT:
            std::cout << endl << "Left" << endl;  // key left
            direction=KEY_LEFT;
            validMove = collisionCheck(direction, gamePiece.getPieceLength(), x, y);
            break;
        case KEY_RIGHT:
            std::cout << endl << "Right" << endl;  // key right
            direction=KEY_RIGHT;
            validMove = collisionCheck(direction, gamePiece.getPieceLength(), x, y);
            break;
        default:
            std::cout << endl << "null" << endl;  // not arrow
            break;
        }
        placedShips++;
    }
}

int main(){
    Board playerOneBoard(1);
    Board playerTwoBoard(2);

    std::vector<Piece> g = playerOneBoard.getGamePieces();
    // std::cout << playerOneBoard.getTopRowMap() << std::endl;
    // for(const auto & [key, value]: playerOneBoard.getTopRowMap()){
    //     std::cout << key << ": " << value << endl;
    // }
    // for()
    // std::cout << playerOneBoard.getGamePieces() << std::endl;


    Node** nodeBoardOne = playerOneBoard.createGameBoard();
    Node** nodeBoardTwo = playerTwoBoard.createGameBoard();

    for(Piece p: playerOneBoard.getGamePieces()){
        placeShip(nodeBoardOne, p);
    }

    for(int i = 0; i < playerOneBoard.getBoardWidth(); ++i){
        delete [] nodeBoardOne[i];
        delete [] nodeBoardTwo[i];
    }

    delete [] nodeBoardOne;
    delete [] nodeBoardTwo;

    return 0;
}
