#include <string>
#include <unordered_map>
// #include "Node.h"

class Board {
    public:
        Board(int playerNum);
        ~Board();
        int getBoardHeight();
        int getBoardWidth();
        std::string getPlayer();
        void setPlayer(int newID);
        Node**createGameBoard();
        void makeAttack(int *x, int *y);
        const std::vector<Piece>& getGamePieces();
        const std::unordered_map<int, char>& getTopRowMap();
    private:
        int boardHeight;
        int boardWidth;
        int player;
        std::unordered_map<int, char> topRowMap;
        std::vector<Piece> gamePieces;
};