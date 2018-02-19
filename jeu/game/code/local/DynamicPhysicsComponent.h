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
    ~DynamicPhysicsComponent() {
        level->world->DestroyBody(body);
    }
    
    void initialize(GameObject& obj, Level *nlevel) {
        
        level = nlevel;
        bodyDef.type = b2_dynamicBody;
        bodyDef.position.Set(obj.m_position.x, obj.m_position.y);
        body = level->world->CreateBody(&bodyDef);

        // Define another box shape for our dynamic body.
        dynamicBox.SetAsBox(obj.m_size/2.0f, obj.m_size/2.0f, b2Vec2(obj.m_size/2.0f, obj.m_size/2.0f),0);

        // Define the dynamic body fixture.
        fixtureDef.shape = &dynamicBox;
        // Set the box density to be non-zero, so it will be dynamic.
        fixtureDef.density = 1.0f;
        // Override the default friction.
        fixtureDef.friction = 0.3f; //0.3f
        //filtre de collisions
        fixtureDef.filter.categoryBits = DEFAULT;
        fixtureDef.filter.maskBits = DEFAULT | TILE | PROTAG;

        // Add the shape to the body.
        body->CreateFixture(&fixtureDef);
        
    }
    
    void update(GameObject& obj){
        
        obj.m_position.x = body->GetPosition().x;
        obj.m_position.y = body->GetPosition().y;
        obj.m_angle = body->GetAngle();
        //body->ApplyLinearImpulse( b2Vec2(obj.m_velocity.x,obj.m_velocity.y), body->GetWorldCenter(), false );
        //obj.m_position += obj.m_velocity;
        //obj.m_velocity = {0.0f,0.0f};
        
    };
    
    void startContact(){};
    void endContact(){};
    int getEntityType() { return ENT_DEFAULT; }
    
    b2BodyDef bodyDef;
    b2Body* body;
    b2PolygonShape dynamicBox;
    b2FixtureDef fixtureDef;
    Level *level;
};

#endif //GF_PHYSICSCOMPONENT_H
