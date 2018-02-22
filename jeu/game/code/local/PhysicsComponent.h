//
// Created by antoine on 18/12/17.
//

#ifndef GF_PHYSICSCOMPONENT_H
#define GF_PHYSICSCOMPONENT_H


#include "GameObject.h"
#include "Level.h"
#include <Box2D/Box2D.h>

extern int numFootContacts;    //nombre de contacts avec le sol du protag
extern int numFootContactsLadder;

enum{   //noms des objets pour les collisions
    ENT_DEFAULT, ENT_PROTAG
};

enum _entityCategory{   //catégories pour les filtres de collision
    DEFAULT =           0x0001,
    PROTAG   =          0x0002,
    FOOT_SENSOR =     0x0004, //la zone où le protag détectera le sol
    TILE =             0x0008,
    LADDER =    0x0010,
 //   FRIENDLY_TOWER =    0x0020,
 //   RADAR_SENSOR =      0x0040,
};

enum _user_date{   //user_data pour les collisions
    UD_DEFAULT, UD_FOOT_SENSOR, UD_ONE_WAY_PLATFORM, UD_LADDER
};

class PhysicsComponent
{
public:
    virtual ~PhysicsComponent() {}
    virtual void initialize(GameObject& obj, Level *level) = 0;
    virtual void update(GameObject& obj) = 0;
    virtual void startContact() = 0;
    virtual void endContact() = 0;
    virtual int getEntityType() = 0;
};



// http://www.iforce2d.net/b2dtut/collision-callbacks

class ContactListener : public b2ContactListener{
    
     void BeginContact(b2Contact* contact) {
          //check if fixture A was the foot sensor
          void* fixtureUserData = contact->GetFixtureA()->GetUserData();
          //printf("mdr %i %i\n", contact->GetFixtureA()->GetFilterData().maskBits, contact->GetFixtureA()->GetFilterData().categoryBits );
          if ( (intptr_t)fixtureUserData == UD_FOOT_SENSOR )
              numFootContacts++;
          if ( (intptr_t)fixtureUserData == UD_LADDER )
              numFootContactsLadder++;
          //check if fixture B was the foot sensor
          fixtureUserData = contact->GetFixtureB()->GetUserData();
          if ( (intptr_t)fixtureUserData == UD_FOOT_SENSOR )
              numFootContacts++;
          if ( (intptr_t)fixtureUserData == UD_LADDER )
              numFootContactsLadder++;
         
         
            b2Fixture* fixtureA = contact->GetFixtureA();
            b2Fixture* fixtureB = contact->GetFixtureB();
        
            //check if one of the fixtures is the platform
            b2Fixture* platformFixture = NULL;
            b2Fixture* otherFixture = NULL;
            if ( (intptr_t)fixtureA->GetUserData() == UD_ONE_WAY_PLATFORM ) {
                platformFixture = fixtureA;
                otherFixture = fixtureB;
            }
            else if ( (intptr_t)fixtureB->GetUserData() == UD_ONE_WAY_PLATFORM ) {
                platformFixture = fixtureB;
                otherFixture = fixtureA;
            }
        
            if ( !platformFixture )
                return;
                
            b2Body* platformBody = platformFixture->GetBody();
            b2Body* otherBody = otherFixture->GetBody();
        
            int numPoints = contact->GetManifold()->pointCount;
            b2WorldManifold worldManifold;
            contact->GetWorldManifold( &worldManifold );
        
            //check if contact points are moving downward
            for (int i = 0; i < numPoints; i++) {
                b2Vec2 pointVelPlatform =
                    platformBody->GetLinearVelocityFromWorldPoint( worldManifold.points[i] );
                b2Vec2 pointVelOther =
                    otherBody->GetLinearVelocityFromWorldPoint( worldManifold.points[i] );
                b2Vec2 relativeVel = platformBody->GetLocalVector( pointVelOther - pointVelPlatform );
                
                if ( relativeVel.y > 0.1f ) //if moving down faster than 1 m/s, handle as before
                    return;//point is moving into platform, leave contact solid and exit
                else if ( relativeVel.y > -0.1f ) { //if moving slower than 1 m/s
                    //borderline case, moving only slightly out of platform
                    b2Vec2 relativePoint = platformBody->GetLocalPoint( worldManifold.points[i] );
                    float platformFaceY = 0.5f;//front of platform, from fixture definition :(
                    if ( relativePoint.y < platformFaceY + 0.05 )
                        return;//contact point is less than 5cm inside front face of platfrom
                }
                //else
                //    ;//moving up faster than 1 m/s
            }
        
            //no points are moving downward, contact should not be solid
            //printf("lol\n");
            contact->SetEnabled(false);
      }
  
      void EndContact(b2Contact* contact) {
          contact->SetEnabled(true);
          
          //check if fixture A was the foot sensor
          void* fixtureUserData = contact->GetFixtureA()->GetUserData();
          if ( (intptr_t)fixtureUserData == UD_FOOT_SENSOR )
              numFootContacts--;
          if ( (intptr_t)fixtureUserData == UD_LADDER )
              numFootContactsLadder--;
          //check if fixture B was the foot sensor
          fixtureUserData = contact->GetFixtureB()->GetUserData();
          if ( (intptr_t)fixtureUserData == UD_FOOT_SENSOR )
             numFootContacts--;
          if ( (intptr_t)fixtureUserData == UD_LADDER )
              numFootContactsLadder--;
      }
};


#endif //GF_PHYSICSCOMPONENT_H
