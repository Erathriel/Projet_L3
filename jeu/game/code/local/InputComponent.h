//
// Created by antoine on 18/12/17.
//

#ifndef GF_INPUTCOMPONENT_H
#define GF_INPUTCOMPONENT_H


#include "GameObject.h"
#include <gf/Event.h>


class GameObject;

class InputComponent
{
public:
    gf::Event event;
    virtual ~InputComponent() {}
    virtual void update(GameObject& obj) = 0;
};


#endif //GF_INPUTCOMPONENT_H