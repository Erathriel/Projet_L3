//
// Created by antoine on 18/12/17.
//

#ifndef GF_PHYSICSCOMPONENT_H
#define GF_PHYSICSCOMPONENT_H


#include "GameObject.h"
#include "Level.h"

class Level;

class PhysicsComponent
{
public:
    virtual ~PhysicsComponent() {}
    virtual void update(GameObject& obj, Level& level) = 0;
};

#endif //GF_PHYSICSCOMPONENT_H
