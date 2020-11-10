#include "Node.h"

Node::Node(int x, int y){
    xPos = x;
    yPos = y;
    hit = false;
    ship = false;
    north = nullptr;
    south = nullptr;
    east = nullptr;
    west = nullptr;
}

Node::Node(){
    xPos = 1;
    yPos = 2;
    hit = false;
    ship = false;
    north = nullptr;
    south = nullptr;
    east = nullptr;
    west = nullptr;
}

void Node::setHit(){
    hit = !hit;
}

void Node::setShip(){
    ship = !ship;
}

void Node::setNorth(Node* north){
	north = north;
}

void Node::setSouth(Node* south){
	south = south;
}

void Node::setEast(Node* east){
	east = east;
}

void Node::setWest(Node* west){
	west = west;
}

Node* Node::getNorth(){
	return north;
}

Node* Node::getSouth(){
	return south;
}

Node* Node::getEast(){
	return east;
}

Node* Node::getWest(){
	return west;
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