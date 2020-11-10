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

    Node aNode = Node(2, 4);

    cout << aNode.getX() << endl;

    cout << aNode.getY() << endl;



    // Board gameBoard(false);
    // int a = gameBoard.getBoardHeight();

    // cout << a << endl;

    // cout << gameBoard.getBoardWidth() << endl;

    // cout << gameBoard.getBoardHeight() << endl;

    cout << "Hello World" << endl;
    return 0;
}
