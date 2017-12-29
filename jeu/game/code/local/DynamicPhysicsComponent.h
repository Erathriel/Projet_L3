//
// Created by antoine on 18/12/17.
//

#ifndef DYNPHYSICSCOMPONENT_H
#define DYNPHYSICSCOMPONENT_H


#include "GameObject.h"
#include "Level.h"

class Level;

class DynamicPhysicsComponent  : public PhysicsComponent
{
public:
    ~DynamicPhysicsComponent() {}
    
    void update(GameObject& obj, Level& level){
        if(!initialised){
            
            bodyDef.type = b2_dynamicBody;
            bodyDef.position.Set(obj.m_position.x, obj.m_position.y);
            body = level.world->CreateBody(&bodyDef);

            // Define another box shape for our dynamic body.
            dynamicBox.SetAsBox(obj.m_size, obj.m_size);

            // Define the dynamic body fixture.
            fixtureDef.shape = &dynamicBox;
            // Set the box density to be non-zero, so it will be dynamic.
            fixtureDef.density = 1.0f;
            // Override the default friction.
            fixtureDef.friction = 0.3f; //0.3f

            // Add the shape to the body.
            body->CreateFixture(&fixtureDef);
            
            initialised = true;
        }
        
        obj.m_position.x = body->GetPosition().x;
        obj.m_position.y = body->GetPosition().y;
        //m_angle = body->GetAngle();
        //body->ApplyLinearImpulse( b2Vec2(obj.m_velocity.x,obj.m_velocity.y), body->GetWorldCenter(), false );
        //obj.m_position += obj.m_velocity;
        //obj.m_velocity = {0.0f,0.0f};
        
    };
    
    bool initialised = false;
    b2BodyDef bodyDef;
    b2Body* body;
    b2PolygonShape dynamicBox;
    b2FixtureDef fixtureDef;
};

#endif //GF_PHYSICSCOMPONENT_H
