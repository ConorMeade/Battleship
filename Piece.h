#include <string>

class Piece {
    private:
        /*
            1 - Carrier (length = 5)
            2 - Battleship (length = 4)
            3 - Destroyer (length = 3)
            4 - Submaring (length = 3)
            5 - Patrol Boat (length = 2)

        */
        Piece(int num, std::string name, int length, bool destroyed);
        int pieceNum;
        std::string pieceName;
        int pieceLength;
        bool destroyed;
    public:
        int getPieceNum();
        int getPieceLength();
        std::string getPieceName();
        bool isPieceDestroyed();

        void setDestroyed();
        void setPieceNum(int num);
        void setPieceLength(int newLength);
        void setPieceName(std::string newName);
};