//
// Created by root on 22/12/17.
//

#ifndef _PROTAGGRAPHICSC_H
#define _PROTAGGRAPHICSC_H


#include "GameObject.h"
#include "Graphics.h"
#include "GraphicsComponent.h"
#include <gf/Shapes.h>
#include <gf/Event.h>
#include <gf/Vector.h>
#include <gf/Color.h>

class Graphics;

class ProtagGraphicsComponent : public GraphicsComponent
{
public:

    void update(GameObject& obj, Graphics *graphics){
        if(!initialised){
            sprite = new gf::Sprite();
            sprite->setAnchor(gf::Anchor::Center);
            sprite->setTexture(*graphics->getTileTexture());
            sprite->setTextureRect({ 0.635f, 0.0f, 0.035f, 0.035f });
            sprite->setPosition(obj.m_position);
            renderState = new gf::RenderStates();

            initialised = true;
        }
        sprite->setPosition(obj.m_position);
        gf::Matrix3f matrice = gf::identityTransform();
        gf::rotate(matrice, obj.m_angle, obj.m_position);
        renderState->transform = matrice;
        
        graphics->setViewCenter(obj.m_position);
        graphics->draw(sprite, renderState);
    }
    ~ProtagGraphicsComponent(){}

private:
    bool initialised = false;
    gf::Sprite *sprite;
    gf::RenderStates *renderState;
};

#endif

