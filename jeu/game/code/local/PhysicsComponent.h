//
// Created by antoine on 18/12/17.
//

#ifndef GF_PHYSICSCOMPONENT_H
#define GF_PHYSICSCOMPONENT_H


#include "GameObject.h"
#include "Level.h"
#include <Box2D/Box2D.h>

class Level;

class PhysicsComponent
{
public:
    virtual ~PhysicsComponent() {}
    virtual void update(GameObject& obj, Level *level) = 0;
    virtual void startContact() = 0;
    virtual void endContact() = 0;
};

// http://www.iforce2d.net/b2dtut/collision-callbacks

class ContactListener : public b2ContactListener{
    
    void BeginContact(b2Contact* contact) {

        //check if fixture A was a ball
        void* bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();
        if ( bodyUserData )
            static_cast<PhysicsComponent*>( bodyUserData )->startContact();

        
        //check if fixture B was a ball
        bodyUserData = contact->GetFixtureB()->GetBody()->GetUserData();
        if ( bodyUserData )
            static_cast<PhysicsComponent*>( bodyUserData )->startContact();

    }

    void EndContact(b2Contact* contact) {

        //check if fixture A was a ball
        void* bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();
        if ( bodyUserData )
            static_cast<PhysicsComponent*>( bodyUserData )->endContact();

        //check if fixture B was a ball
        bodyUserData = contact->GetFixtureB()->GetBody()->GetUserData();
        if ( bodyUserData )
            static_cast<PhysicsComponent*>( bodyUserData )->endContact();

    }
};


#endif //GF_PHYSICSCOMPONENT_H
