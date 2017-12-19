//
// Created by antoine on 18/12/17.
//

#ifndef GF_PHYSICSCOMPONENT_H
#define GF_PHYSICSCOMPONENT_H


#include "GameObject.h"

class PhysicsComponent
{
public:
    virtual ~PhysicsComponent() {}
    virtual void update(GameObject& obj, World& world) = 0;
};

#endif //GF_PHYSICSCOMPONENT_H
