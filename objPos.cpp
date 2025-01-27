#include "objPos.h"


// Purpose of this constructor?
// Creates a new object position at (0,0) position, and sets a null symbol
// Default state for each object
objPos::objPos()
{
    pos = new Pos;
    pos->x = 0;
    pos->y = 0;
    symbol = 0; //NULL
}

// ObjPosition at a specfic value and symbol
// Dynamic allocation for Pos object on the heap
objPos::objPos(int xPos, int yPos, char sym)
{
    pos = new Pos;
    pos->x = xPos; // Sets the x-coordinate to the provided value
    pos->y = yPos; // Sets the y-coordinate to the provided value
    symbol = sym; // Sets the symbol to the provided character
}

// Respect the rule of six / minimum four
// [TODO] Implement the missing special member functions to meet the minimum four rule

// Iteration 0
// The destructor
objPos::~objPos(){
    delete pos; // Frees the memory allocated
}

// Copy Constructor
objPos::objPos (const objPos& other){
    pos = new Pos; // Memory Allocate
    pos -> x = other.pos -> x; // Copies x
    pos -> y = other.pos -> y; // Copies y
    symbol = other.symbol; // Copies the symbol from the source object
}

// Copy Assignment operator (Deep Copy)
objPos &objPos::operator=(const objPos& other){
    if(this == &other){ // Checks for self-assignment
        return *this; // Returns the current object if self-assignment is detected
    }
    else{
        delete pos;
        pos = new Pos; // Memory Alloicate
        pos -> x = other.pos -> x; // Copies x
        pos -> y = other.pos -> y; // Copies y
        symbol = other.symbol;  // Copies the symbol from the source object  
    }
    return *this;
}



// The setter
// Updates current object position and symbol by copying another objPos object
// Can be used to move the snakes head to the position as another object
void objPos::setObjPos(objPos o)
{
    pos->x = o.pos->x;
    pos->y = o.pos->y;
    symbol = o.symbol;
}

// Updates the position and symbol of the current object to the specified values.
// Can be used to set the snake's head or food to a specific position on the game board.
void objPos::setObjPos(int xPos, int yPos, char sym)
{
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

// Creates and Returns the copy objPos Object
objPos objPos::getObjPos() const
{
    objPos returnPos;
    returnPos.pos->x = pos->x;
    returnPos.pos->y = pos->y;
    returnPos.symbol = symbol;
    
    return returnPos;
}

// Check the symbol and return symbol
// The snake or food
char objPos::getSymbol() const
{
    return symbol;
}

// Does this object position match another object's Position?
// True or False
// Did the snake eat food, or bite its self???
// Will be used with the previous function
bool objPos::isPosEqual(const objPos* refPos) const
{
    return (refPos->pos->x == pos->x && refPos->pos->y == pos->y);
}

// Returns the symbol of the current object if its position matches the given reference position.
// Returns 0 (null) if the positions do not match.
// Useful for identifying the type of object (e.g., snake, food) at a specific position during gameplay.
char objPos::getSymbolIfPosEqual(const objPos* refPos) const
{
    if(isPosEqual(refPos))
        return symbol;
    else
        return 0;
}
