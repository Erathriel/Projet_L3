//
// Created by root on 22/12/17.
//

#ifndef _BEEGRAPHICSC_H
#define _BEEGRAPHICSC_H


#include "GameObject.h"
#include "Graphics.h"
#include "GraphicsComponent.h"
#include <gf/Shapes.h>
#include <gf/Event.h>
#include <gf/Vector.h>
#include <gf/Color.h>


#define SIZE 0.033333333334

class Graphics;

class BeeGraphicsComponent : public GraphicsComponent
{
public:
    
    void initialize(GameObject& obj, Graphics *ngraphics){
        graphics = ngraphics;
        sprite = new gf::Sprite();
        sprite->setAnchor(gf::Anchor::Center);
        sprite->setTexture(*graphics->getTileTexture());
        sprite->setTextureRect({ (24*SIZE), (12*SIZE), SIZE, SIZE });
        sprite->setPosition(obj.m_position);
        renderState = new gf::RenderStates();

    }

    void update(GameObject& obj){
        sprite->setPosition(obj.m_position);
        gf::Matrix3f matrice = gf::identityTransform();
        gf::rotate(matrice, obj.m_angle, obj.m_position);
        renderState->transform = matrice;
        graphics->draw(sprite, renderState);
    }
    ~BeeGraphicsComponent(){
        delete sprite;
        delete renderState;
    }

private:
    Graphics *graphics;
    gf::Sprite *sprite;
    gf::RenderStates *renderState;
};

#endif

