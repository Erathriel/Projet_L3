//
// Created by antoine on 18/12/17.
//

#ifndef GF_PHYSICSCOMPONENT_H
#define GF_PHYSICSCOMPONENT_H


#include "GameObject.h"
#include "Level.h"
#include <Box2D/Box2D.h>

extern int numFootContacts;    //nombre de contacts avec le sol du protag

enum{   //noms des objets pour les collisions
    ENT_DEFAULT, ENT_PROTAG
};

enum _entityCategory{   //catégories pour les filtres de collision
    DEFAULT =           0x0001,
    PROTAG   =          0x0002,
    FOOT_SENSOR =     0x0004, //la zone où le protag détectera le sol
    SOLID =             0x0008,
 //   ENEMY_AIRCRAFT =    0x0010,
 //   FRIENDLY_TOWER =    0x0020,
 //   RADAR_SENSOR =      0x0040,
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
          if ( (intptr_t)fixtureUserData == 3 )
              numFootContacts++;
          //check if fixture B was the foot sensor
          fixtureUserData = contact->GetFixtureB()->GetUserData();
          if ( (intptr_t)fixtureUserData == 3 )
              numFootContacts++;
      }
  
      void EndContact(b2Contact* contact) {
          //check if fixture A was the foot sensor
          void* fixtureUserData = contact->GetFixtureA()->GetUserData();
          if ( (intptr_t)fixtureUserData == 3 )
              numFootContacts--;
          //check if fixture B was the foot sensor
          fixtureUserData = contact->GetFixtureB()->GetUserData();
          if ( (intptr_t)fixtureUserData == 3 )
             numFootContacts--;
      }
};


#endif //GF_PHYSICSCOMPONENT_H
