#include <iostream>
#include <vector>
#include <string>
#include "Node.h"
#include "Board.h"


using namespace std;


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


    Node** nodeBoard = playerOneBoard.createGameBoard();

    for(int i = 0; i < playerOneBoard.getBoardHeight(); ++i){
        for(int j = 0; j < playerOneBoard.getBoardWidth(); ++j){
            cout << "X: " << nodeBoard[i][j].getX() << " Y: " << nodeBoard[i][j].getY() << endl;
        }
    }

    // for(int i = 0; i < 10; ++i){
    //     for(int j = 0; j < 10; ++j){
    //         cout << (test[i][j]) << endl;
    //     }
    // }
    // Node** a = playerOneBoard.createGameBoard();

    for(int i = 0; i < playerOneBoard.getBoardWidth(); ++i){
        delete [] nodeBoard[i];
    }

    delete [] nodeBoard;

    cout << "Hello World" << endl;
    return 0;
}
