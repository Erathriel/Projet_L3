//
// Created by antoine on 18/12/17.
//

#ifndef GF_INPUTCOMPONENT_H
#define GF_INPUTCOMPONENT_H


#include "GameObject.h"
#include "Level.h"
#include <gf/Event.h>


class GameObject;
class Level;

class InputComponent
{
public:
    gf::Event event;
    virtual ~InputComponent() {}
    virtual void update(GameObject& obj, Level *level) = 0;
};


#endif //GF_INPUTCOMPONENT_H
