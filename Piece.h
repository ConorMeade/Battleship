#include <string>

class Piece {
    public:
        Piece(int num, std::string name, int length, bool destroyed);
        int getPieceNum();
        int getPieceLength();
        std::string getPieceName();
        bool isPieceDestroyed();

        void setDestroyed();
        void setPieceNum(int num);
        void setPieceLength(int newLength);
        void setPieceName(std::string newName);

    private:
        int pieceNum;
        std::string pieceName;
        int pieceLength;
        bool destroyed;
};