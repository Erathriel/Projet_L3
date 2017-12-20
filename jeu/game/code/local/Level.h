#ifndef _LEVEL_H
#define _LEVEL_H


#include "GameObject.h"

class GameObject;

class Level {
  private:
    int number;
    float dt;
    void update(GameObject& obj);
    //Object* list;

public:
    void setdt(float ndt);
    float getdt();
};
#endif
