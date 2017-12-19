//
// Created by antoine on 18/12/17.
//

#ifndef GF_INPUTCOMPONENT_H
#define GF_INPUTCOMPONENT_H


#include "GameObject.h"

class GameObject;

class InputComponent
{
public:
    virtual ~InputComponent() {}
    virtual void update(GameObject& obj) = 0;
};


#endif //GF_INPUTCOMPONENT_H
