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


#define SIZE 0.033333333334
#define PERSONNAGE 19

class Graphics;

class SpriteGraphicsComponent : public GraphicsComponent
{
public:
    
    void initialize(GameObject& obj, Graphics *graphics){
        sprite = new gf::Sprite();
        sprite->setAnchor(gf::Anchor::Center);
        sprite->setTexture(*graphics->getTileTexture());
        sprite->setTextureRect({ (PERSONNAGE*SIZE), (3*SIZE), SIZE, SIZE });
        sprite->setPosition(obj.m_position);
        renderState = new gf::RenderStates();

    }

    void update(GameObject& obj, Graphics *graphics){
        sprite->setPosition(obj.m_position);
        gf::Matrix3f matrice = gf::identityTransform();
        gf::rotate(matrice, obj.m_angle, obj.m_position);
        renderState->transform = matrice;
        graphics->draw(sprite, renderState);
    }
    ~SpriteGraphicsComponent(){
        delete sprite;
        delete renderState;
    }

private:
    gf::Sprite *sprite;
    gf::RenderStates *renderState;
};

#endif

