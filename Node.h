class Node {
    public:
        Node(int x, int y);
        Node();

        char getState();
        bool getHit();
        bool getShip();
        int getX();
        int getY();
        
        void setState(char newState);
        void setHit();
        void setShip();
        void setX(int xCord);
        void setY(int yCord);


    private:
        char state;
        int xPos;
        int yPos;
        bool ship;
        bool hit;
};