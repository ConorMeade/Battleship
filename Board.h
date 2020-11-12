#include <string>
// #include "Node.h"

// class Node;

class Board {
    private:
        int boardHeight;
        int boardWidth;
        int player;
        // int** gameBoard;
        // int** gameBoard;
    public:
        Board(int playerNum);
        ~Board();
        int getBoardHeight();
        int getBoardWidth();
        std::string getPlayer();
        void setPlayer();
        Node**createGameBoard();
        void makeAttack(int *x, int *y);
        void printGameBoard(const Board& board);
};