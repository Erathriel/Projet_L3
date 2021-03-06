//
// Created by antoine on 18/12/17.
//

#ifndef PROTAGPHYSICSCOMPONENT_H
#define PROTAGPHYSICSCOMPONENT_H


#include "GameObject.h"
#include "Level.h"

#define JUMP_TIME_MAX   45
#define JUMP_TIMEOUT    20

extern int numFootContacts;
extern int numFootContactsLadder;
extern bool touchedExit;

class Level;

class ProtagPhysicsComponent  : public PhysicsComponent
{
public:
    ~ProtagPhysicsComponent() {
        printf("P0\n");
        level->world->DestroyBody(body);
        printf("P1\n");
        //delete fixtureFS;
        printf("P2\n");
    }
    
    void initialize(GameObject& obj, Level *nlevel) {
        numFootContacts = 0;
        numFootContactsLadder = 0;
        touchedExit = false;
        level = nlevel;
        
        bodyDef.type = b2_dynamicBody;
        bodyDef.position.Set(obj.m_position.x, obj.m_position.y);
        bodyDef.fixedRotation = true; //le protag ne doit pas rotater
        
        body = level->world->CreateBody(&bodyDef);

        // Define another box shape for our dynamic body.
        dynamicBox.SetAsBox(obj.m_size/2.0f, obj.m_size/2.0f, b2Vec2(obj.m_size/2.0f, obj.m_size/2.0f),0);

        // Define the dynamic body fixture.
        fixtureDef.shape = &dynamicBox;
        // Set the box density to be non-zero, so it will be dynamic.
        fixtureDef.density = 1.0f;
        // Override the default friction.
        fixtureDef.friction = 0.0f; //0.3f
        //filtre de collisions
        fixtureDef.filter.categoryBits = PROTAG;
        fixtureDef.filter.maskBits = DEFAULT | TILE | LADDER;

        // Add the shape to the body.
        body->CreateFixture(&fixtureDef);
        
        //pour les collisions (détecté par ContactListener)
        //body->SetUserData( this );
        
        //add foot sensor fixture
        boxShapeGS.SetAsBox(obj.m_size/2.1f, 1.0f, b2Vec2(obj.m_size/2.0f,obj.m_size), 0);
        fixtureDefFS.shape = &boxShapeGS;
        fixtureDefFS.isSensor = true;
        fixtureDef.filter.categoryBits = FOOT_SENSOR;
        fixtureDef.filter.maskBits = DEFAULT | TILE | LADDER;
        fixtureFS = body->CreateFixture(&fixtureDefFS);
        fixtureFS->SetUserData( (void*)UD_FOOT_SENSOR );
        
    }
    
    void update(GameObject& obj){
        
        if(touchedExit){
            level->endLevel();
            touchedExit = false;
        }
        
        obj.m_position.x = body->GetPosition().x;
        obj.m_position.y = body->GetPosition().y;
        
        float impulseX = 0.0f;
        float impulseY = 0.0f;
        
        if(numFootContactsLadder > 0)
            jumpTime = 1;
        
        if(numFootContacts > 0 && (jumpTimeout < 0 || jumpTimeout > 60)){
            onGround = true;
            jumpTime = 0;
        }
        else{
            onGround = false;
            if(obj.m_velocity.y >= 0.0f)
                jumpTime = JUMP_TIME_MAX;
        }
        
        
        b2Vec2 vel = body->GetLinearVelocity();
        float velChange = obj.m_velocity.x - vel.x;
        //if( (velChange > 0 && obj.m_velocity.x > 0)
        //    || (velChange < 0 && obj.m_velocity.x < 0))
            impulseX = body->GetMass() * velChange; //disregard time factor
        //if(!onGround && jumpTime > 30)
        //    impulseX /= 10;
        
        if(obj.m_velocity.y < -0.1f && (onGround || (jumpTime > 0 && jumpTime < JUMP_TIME_MAX) )){
            velChange = obj.m_velocity.y - vel.y;
            impulseY = body->GetMass() * velChange;
            jumpTimeout = JUMP_TIMEOUT;
            jumpTime ++;
        }
        
        if(impulseX != 0.0f || impulseY != 0.0f)
            body->ApplyLinearImpulse( b2Vec2(impulseX, impulseY), body->GetWorldCenter(), true );
        
        //obj.m_angle = body->GetAngle();
        //obj.m_position += obj.m_velocity;
        obj.m_velocity = {0.0f,0.0f};
        //printf("%f %f\n", impulseX, impulseY);
        
        jumpTimeout--;
        
    };
    
    void startContact() { numFootContacts++; }
    void endContact() { numFootContacts--; }
    int getEntityType() { return ENT_PROTAG; }

    bool onGround = false;
    int jumpTimeout = 0;
    int jumpTime = JUMP_TIME_MAX;
    b2BodyDef bodyDef;
    b2Body* body;
    b2PolygonShape dynamicBox;
    b2PolygonShape boxShapeGS;
    b2FixtureDef fixtureDef;
    b2FixtureDef fixtureDefFS;
    b2Fixture* fixtureFS;
    Level *level;
};

#endif //GF_PHYSICSCOMPONENT_H
