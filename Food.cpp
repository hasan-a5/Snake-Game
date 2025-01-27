#include "Food.h"
#include <cstdlib>  // For rand()
#include <ctime>    // For time()



// Constructor: Initialize food position and symbol
Food::Food(GameMechs* thisGMRef): gameMechsRef(thisGMRef) {
    foodPos.pos->x = 0;           // Default x position
    foodPos.pos->y = 0;           // Default y position
    foodPos.symbol = 'x';    // Default symbol for food
    srand(time(nullptr));    // Seed the random number generator
}

// Destructor: If there's any dynamic memory, free it here (not necessary for this case)
Food::~Food() {

}

// Generate a random position for food, avoiding the player's position
void Food::generateFood(objPosArrayList& blockOff) {
    int x, y;
    char symbol = 'x';  // Food symbol
    bool unique = false;

    int boardX = gameMechsRef->getBoardSizeX() - 2;
    int boardY = gameMechsRef->getBoardSizeY() - 2;

    while (!unique) {

        // Randomly generate x and y within bounds
        x = rand() % (boardX - 1) + 1;  // x range [1, 18]
        y = rand() % (boardY - 1) + 1;  // y range [1, 8]

        // Ensure the food doesn't overlap with the player (blockOff position)
        unique = true;

        for (int i = 0; i <blockOff.getSize(); i++){    
            objPos snakeSegment = blockOff.getElement(i);
            if (x == snakeSegment.pos->x && y == snakeSegment.pos->y) {
                unique = false;
                break;
            }
        }

        // If the position is unique, set the food's position
        if(unique){
            foodPos.pos->x = x;
            foodPos.pos->y = y;
            foodPos.symbol = symbol;
        }
    }
}

// Return the current food position
objPos Food::getFoodPos() const {
    return foodPos;
}
