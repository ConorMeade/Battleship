#include "Node.h"

Node::Node(int x, int y){
    xPos = x;
    yPos = y;
    state = 'O';
    hit = false;
    ship = false;

}

Node::Node(){
    xPos = 1;
    yPos = 2;
    hit = false;
    state = 'O';
}

void Node::setState(char newState){
    state = newState;
}

void Node::setHit(){
    hit = !hit;
}

void Node::setShip(){
    ship = !ship;
}

char Node::getState(){
    return state;
}

bool Node::getHit(){
    return hit;
}

bool Node::getShip(){
    return ship;
}

int Node::getX(){
    return xPos;
}

int Node::getY(){
    return yPos;
}

void Node::setX(int xCord){
    xPos = xCord;
}

void Node::setY(int yCord){
    yPos = yCord;
}