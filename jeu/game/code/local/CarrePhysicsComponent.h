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
    void update(GameObject& obj, Level *level){
        obj.m_position += obj.m_velocity;
        //printf("%f %f\n", obj.m_position.x, obj.m_velocity.x);
    };
    void startContact(){};
    void endContact(){};
};

#endif //GF_PHYSICSCOMPONENT_H
