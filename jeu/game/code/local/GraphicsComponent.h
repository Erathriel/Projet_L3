//
// Created by antoine on 18/12/17.
//

#ifndef GF_GRAPHICSCOMPONENT_H
#define GF_GRAPHICSCOMPONENT_H


#include "GameObject.h"
#include "Graphics.h"

class Graphics;

class GraphicsComponent
{
public:
    virtual ~GraphicsComponent() {}
    virtual void update(GameObject& obj, Graphics graphics) = 0;
};


#endif //GF_GRAPHICSCOMPONENT_H
