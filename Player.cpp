#include "Player.h"
#include "objPosArrayList.h"
#include "Food.h"
#include "GameMechs.h"

// Constructor
// Initializes the player object with references to the game mechanics and food objects.
// Sets the initial direction to STOP and positions the player's head at the center of the board.
Player::Player(GameMechs* thisGMRef, Food* thisFoodRef)
{
    mainGameMechsRef = thisGMRef;
    foodRef = thisFoodRef;
    playerPosList = new objPosArrayList();
    direction = STOP;

    objPos headPos(mainGameMechsRef -> getBoardSizeX() / 2, mainGameMechsRef -> getBoardSizeY() / 2,'@');

    playerPosList->insertHead(headPos);
}

// Cleans up dynamically allocated resources
Player::~Player()
{
    // delete any heap members here
    delete playerPosList;
    playerPosList = nullptr;
}

objPosArrayList* Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    return playerPosList;
}

// Updates the player's direction based on input from the game mechanics.
// Ensures that the player cannot reverse directly into itself.
void Player::updatePlayerDir()
{
    char input = mainGameMechsRef -> getInput();
  
    switch(input){                      
            case 'w': case 'W':
                if (direction == LEFT || direction == RIGHT || direction == STOP)
                {
                    direction = UP;
                }
                break;
            case 'a': case 'A':
                if (direction == UP || direction == DOWN || direction == STOP)
                {
                    direction = LEFT;
                }
                break;
            case 's':  case 'S':
                if (direction == LEFT || direction == RIGHT || direction == STOP)
                {
                    direction = DOWN;
                }
                break;
            case 'd': case 'D':
                if (direction == UP || direction == DOWN || direction == STOP)
                {
                    direction = RIGHT;
                }
                break;
            default:
                break;
        }    
}

// Moves the player's position based on the current direction
// Handles wrapping around the board and checks for food consumption or self-collision
void Player::movePlayer()
{
    objPos head = playerPosList->getHeadElement();
    
    if (direction == UP){
        head.pos->y -= 1;
        if (head.pos-> y == 0){
            head.pos-> y = mainGameMechsRef->getBoardSizeY() - 1;
        }
    }
    else if (direction == DOWN){
        head.pos->y += 1;
        if (head.pos-> y == mainGameMechsRef->getBoardSizeY()){
            head.pos-> y = 1;
        }
    }
    else if (direction == LEFT){
        head.pos->x -= 1;
        if (head.pos-> x == 0){
            head.pos-> x = mainGameMechsRef->getBoardSizeX() - 1;
        }
    }
    else if (direction == RIGHT){
        head.pos->x += 1;
        if (head.pos-> x == mainGameMechsRef->getBoardSizeX()){
            head.pos-> x = 1;
        }
    }

    // Checks if the player eats food.
    if(head.pos->x == foodRef->getFoodPos().pos-> x && head.pos->y == foodRef->getFoodPos().pos-> y){
        playerPosList->insertHead(head); // Adds the new head position to list
        foodRef->generateFood(*playerPosList); // Generates new food at a random location
        mainGameMechsRef->incrementScore(); // Increments score
    }
    else{
        playerPosList->insertHead(head);
        playerPosList->removeTail();
    }

    if(checkSelfCollision()){
        mainGameMechsRef->setLoseFlag();
        mainGameMechsRef->setExitTrue();
    }
}

// Self collision
// Checks if the player's head position collides with any part of its body and returns a true or false
bool Player::checkSelfCollision(){
    objPos head = playerPosList->getHeadElement();

    for(int i = 1; i < playerPosList->getSize(); i++) { // Iterates through the body segments to check for collision
        objPos bodySegment = playerPosList->getElement(i); // Gets each body segment
        if(head.pos->x == bodySegment.pos->x && head.pos->y == bodySegment.pos->y){
            return true; // Collision Occurs
        } 
    }
    return false; // No Collision
}