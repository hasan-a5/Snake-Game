#ifndef FOOD_H
#define FOOD_H

#include "objPos.h"
#include "objPosArrayList.h"
#include "GameMechs.h"

class Food
{
    private:
        objPos foodPos;
        GameMechs* gameMechsRef;
    
    public:
        Food(GameMechs* ThisGMRef);
        ~Food();

        void generateFood(objPosArrayList& blockOff);
        objPos getFoodPos() const;
};

#endif