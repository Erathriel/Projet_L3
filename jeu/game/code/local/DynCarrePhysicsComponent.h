//
// Created by antoine on 18/12/17.
//

#ifndef CARREPHYSICSCOMPONENT_H
#define CARREPHYSICSCOMPONENT_H


#include "GameObject.h"
#include "Level.h"

class Level;

class DynCarrePhysicsComponent  : public PhysicsComponent
{
public:
    ~DynCarrePhysicsComponent() {}
    
    void update(GameObject& obj, Level& level){
        if(!initialised){
            
            bodyDef.type = b2_dynamicBody;
            bodyDef.position.Set(0.0f, 4.0f);
            body = world.CreateBody(&bodyDef);

            // Define another box shape for our dynamic body.
            dynamicBox.SetAsBox(1.0f, 1.0f);

            // Define the dynamic body fixture.
            fixtureDef.shape = &dynamicBox;
            // Set the box density to be non-zero, so it will be dynamic.
            fixtureDef.density = 1.0f;
            // Override the default friction.
            fixtureDef.friction = 0.3f;

            // Add the shape to the body.
            body->CreateFixture(&fixtureDef);
            
            initialised = true;
        }
        
        obj.m_position.x = body->GetPosition().x;
        obj.m_position.y = body->GetPosition().y;
        //m_angle = body->GetAngle();
        //obj.m_position += obj.m_velocity;
        //printf("%f %f\n", obj.m_position.x, obj.m_velocity.x);
        
    };
    
    bool initialised = false;
    b2BodyDef bodyDef;
    b2Body* body;
    b2PolygonShape dynamicBox;
    b2FixtureDef fixtureDef;
};

#endif //GF_PHYSICSCOMPONENT_H
