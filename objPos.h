#ifndef OBJPOS_H
#define OBJPOS_H

// Not really a C++ thing
typedef struct 
{
    int x;
    int y;
} Pos; // Will hold x and y coordinates 
       // it will track the snake's body and the food for the snake

// Purpose of this class?
// The Purpose of this class is to create objects (or instantces of the class)
// We will need this for the food and snake
class objPos
{
    public:
        Pos* pos;        
        char symbol;

        objPos(); // initialzes a position at (0,0) I know this because?
        objPos(int xPos, int yPos, char sym); // Sets a specific position and symbol
        
        // Respect the rule of six / minimum four
        // [TODO] Implement the missing special member functions to meet the minimum four rule
        // Importnant for Pos *pos DMA
        ~objPos(); // Destructor
        objPos (const objPos& other);
        objPos& operator=(const objPos& other);

        void setObjPos(objPos o);  // The Setter     
        void setObjPos(int xPos, int yPos, char sym); //Set Position and symbol 

        objPos getObjPos() const; // The getter
        char getSymbol() const; // Returns the symbol and object position
        char getSymbolIfPosEqual(const objPos* refPos) const; // Return the symbol if two objects have the same position
        
        bool isPosEqual(const objPos* refPos) const;
};

#endif