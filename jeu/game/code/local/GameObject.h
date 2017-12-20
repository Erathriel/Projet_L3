//
// Created by antoine on 18/12/17.
//

#ifndef GF_GAMEOBJECT_H
#define GF_GAMEOBJECT_H

#include <gf/Vector.h>
#include "InputComponent.h"
#include "PhysicsComponent.h"
#include "GraphicsComponent.h"
#include "Graphics.h"
#include "Level.h"

class Level;

class GameObject
{
public:
    gf::Vector2f m_velocity;
    gf::Vector2f m_position;
    float m_size;
    gf::Color4f m_color;


    GameObject(InputComponent* input, PhysicsComponent* physics, GraphicsComponent* graphics, gf::Vector2f position, float size, gf::Color4f color);

    void update(Level& level, Graphics& graphics);

    void update(Graphics& graphics);

    void setVelocity(gf::Vector2f velocity);


private:
    
    InputComponent* input_;
    PhysicsComponent* physics_;
    GraphicsComponent* graphics_;
};


#endif //GF_GAMEOBJECT_H
