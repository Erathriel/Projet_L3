//
// Created by antoine on 18/12/17.
//

#ifndef GF_GRAPHICSCOMPONENT_H
#define GF_GRAPHICSCOMPONENT_H


#include "GameObject.h"
#include "Graphics.h"

class GraphicsComponent
{
public:
    virtual ~GraphicsComponent() {}
    virtual void update(GameObject& obj) = 0;
};


#endif //GF_GRAPHICSCOMPONENT_H
