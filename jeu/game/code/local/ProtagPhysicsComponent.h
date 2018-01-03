//
// Created by antoine on 18/12/17.
//

#ifndef PROTAGPHYSICSCOMPONENT_H
#define PROTAGPHYSICSCOMPONENT_H


#include "GameObject.h"
#include "Level.h"

class Level;

class ProtagPhysicsComponent  : public PhysicsComponent
{
public:
    ~ProtagPhysicsComponent() {}
    
    void update(GameObject& obj, Level *level){
        if(!initialised){
            
            bodyDef.type = b2_dynamicBody;
            bodyDef.position.Set(obj.m_position.x, obj.m_position.y);
            bodyDef.fixedRotation = true; //le protag ne doit pas rotater
            
            body = level->world->CreateBody(&bodyDef);

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
            
            //pour les collisions (détecté par ContactListener)
            body->SetUserData( this );
        }
        
        obj.m_position.x = body->GetPosition().x;
        obj.m_position.y = body->GetPosition().y;
        
        if(numContacts > 0)
            onGround = true;
        else
            onGround = false;
        
        b2Vec2 vel = body->GetLinearVelocity();
        float velChange = obj.m_velocity.x - vel.x;
        float impulse = body->GetMass() * velChange; //disregard time factor
        body->ApplyLinearImpulse( b2Vec2(impulse,0), body->GetWorldCenter(), true );
        
        if(obj.m_velocity.y < -0.1f && onGround){
            float impulse = body->GetMass() * -10;
            body->ApplyLinearImpulse( b2Vec2(0,impulse), body->GetWorldCenter(), true );
        }
        //obj.m_angle = body->GetAngle();
        //obj.m_position += obj.m_velocity;
        obj.m_velocity = {0.0f,0.0f};
        //printf("%f %f\n", obj.m_position.x, obj.m_velocity.x);
        
    };
    
    void startContact() { numContacts++; }
    void endContact() { numContacts--; }
    
    bool initialised = false;
    bool onGround = false;
    int numContacts = 0;
    b2BodyDef bodyDef;
    b2Body* body;
    b2PolygonShape dynamicBox;
    b2FixtureDef fixtureDef;
};

#endif //GF_PHYSICSCOMPONENT_H
