#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Piece.h"


Piece::Piece(int num, std::string name, int length, bool destroyed){
    pieceNum = num;
    pieceName = name;
    pieceLength = length;
    destroyed = destroyed;
}

int Piece::getPieceNum(){
    return pieceNum;
}

int Piece::getPieceLength(){
    return pieceLength;
}

std::string Piece::getPieceName(){
    return pieceName;
}

bool Piece::isPieceDestroyed(){
    return destroyed;
}

void Piece::setDestroyed(){
    destroyed = true;
}

void Piece::setPieceNum(int num){
    if(num < 1 || num > 5){
        throw "Out of bounds for a valid piece number";
    }else{
        pieceNum = num;
    }
}

void Piece::setPieceLength(int newLength){
    if(newLength <= 0 || newLength >= 10){
        throw "Out of bounds for a valid piece length";
    }else{
        pieceLength = newLength;
    }
}

void Piece::setPieceName(std::string newName){
    pieceName = newName;
}