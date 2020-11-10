#include <string>
// #include "Node.h"

class Board {
    private:
        int boardHeight;
        int boardWidth;
        bool player;
        // int** gameBoard;
    public:
        Board(bool playerNum);
        ~Board();
        int getBoardHeight();
        int getBoardWidth();
        std::string getPlayer();
        void createGameBoard(int height, int width);
        void printGameBoard();

};