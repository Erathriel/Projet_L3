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
    ~CarrePhysicsComponent() {}
    void update(GameObject& obj, Level& level){};
};

#endif //GF_PHYSICSCOMPONENT_H
