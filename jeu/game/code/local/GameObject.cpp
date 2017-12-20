//
// Created by antoine on 18/12/17.
//



#include "GameObject.h"


GameObject::GameObject(InputComponent* input, PhysicsComponent* physics, GraphicsComponent* graphics, gf::Vector2f position, float size, gf::Color4f color) {
    input_ = input;
    physics_= physics;
    graphics_ = graphics;
    m_velocity.x = 0;
    m_velocity.y = 0;
    m_size = size;
    m_color = color;
    m_position = position;

}

void GameObject::update(Level& level, Graphics& graphics)
    {
        printf("a\n");
        input_->update(*this);
        printf("b\n");
        physics_->update(*this, level);
        printf("c\n");
        graphics_->update(*this, &graphics);
        printf("d\n");
    }


void GameObject::update(Graphics& graphics)
    {
        graphics_->update(*this, &graphics);
    }

