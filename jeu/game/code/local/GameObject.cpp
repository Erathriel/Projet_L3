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
        input_->update(*this);
        physics_->update(*this, level);
        graphics_->update(*this, graphics);
    }


