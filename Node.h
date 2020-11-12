class Node {
    public:
        Node(int x, int y);
        Node();
        
        Node* getNorth();
        Node* getSouth();
        Node* getEast();
        Node* getWest();
        bool getHit();
        bool getShip();
        int getX();
        int getY();
        

        void setNorth(Node* north);
        void setSouth(Node* south);
        void setEast(Node* east);
        void setWest(Node* west);
        void setHit();
        void setShip();
        void setX(int xCord);
        void setY(int yCord);


        private:
            Node* north;
            Node* south;
            Node* east;
            Node* west;
            int xPos;
            int yPos;
            bool ship;
            bool hit;


};