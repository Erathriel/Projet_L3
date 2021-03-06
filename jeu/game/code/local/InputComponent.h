//
// Created by antoine on 18/12/17.
//

#ifndef GF_INPUTCOMPONENT_H
#define GF_INPUTCOMPONENT_H


#include "GameObject.h"
#include "Level.h"
#include "Graphics.h"
#include <gf/Event.h>


class GameObject;
class Level;
class Graphics;

class InputComponent
{
public:
    gf::Event event;
    virtual ~InputComponent() {}
    virtual void initialize(GameObject& obj, Level *level, Graphics *graphics) = 0;
    virtual void update(GameObject& obj) = 0;
};


#endif //GF_INPUTCOMPONENT_H
