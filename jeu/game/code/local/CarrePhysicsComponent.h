//
// Created by antoine on 18/12/17.
//

#ifndef CARREPHYSICSCOMPONENT_H
#define CARREPHYSICSCOMPONENT_H


#include "GameObject.h"
#include "Level.h"

class Level;

class CarrePhysicsComponent  : public PhysicsComponent
{
public:
    //~PhysicsComponent() {}
    void update(GameObject& obj, Level& level) = 0;
};

#endif //GF_PHYSICSCOMPONENT_H
