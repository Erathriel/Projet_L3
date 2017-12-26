//
// Created by root on 22/12/17.
//

#ifndef _SPRITEGRAPHICSC_H
#define _SPRITEGRAPHICSC_H


#include "GameObject.h"
#include "Graphics.h"
#include "GraphicsComponent.h"
#include <gf/Shapes.h>
#include <gf/Event.h>
#include <gf/Vector.h>
#include <gf/Color.h>

class Graphics;

class SpriteGraphicsComponent : public GraphicsComponent
{
public:

    void update(GameObject& obj, Graphics *graphics){
        if(!initialised){
            sprite = new gf::Sprite();
            sprite->setTexture(*graphics->getTileTexture());
            sprite->setTextureRect({ 0.635f, 0.0f, 0.035f, 0.035f });
            sprite->setPosition(obj.m_position);

            initialised = true;
        }
        sprite->setPosition(obj.m_position);
        graphics->draw(sprite);
    }
    ~SpriteGraphicsComponent(){}

private:
    bool initialised = false;
    gf::Sprite *sprite;
};

#endif

