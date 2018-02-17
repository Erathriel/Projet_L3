//
// Created by antoine on 18/12/17.
//



#include "GameObject.h"


GameObject::GameObject(InputComponent* input, PhysicsComponent* physics, GraphicsComponent* graphics, gf::Vector2f position, float size, gf::Color4f color, float angle) {
    input_ = input;
    physics_= physics;
    graphics_ = graphics;
    m_velocity = {0.0f,0.0f};
    m_size = size;
    m_color = color;
    m_position = position;
    m_angle = angle;

}

void GameObject::initialize(Level& level, Graphics& graphics){
    //input_->initialize(*this, &level);
    physics_->initialize(*this, &level);
    graphics_->initialize(*this, &graphics);
}

void GameObject::update(Level& level, Graphics& graphics){
    input_->update(*this, &level);
    physics_->update(*this);
    graphics_->update(*this, &graphics);
}


void GameObject::update(Graphics& graphics){
    graphics_->update(*this, &graphics);
}

GameObject::~GameObject(){
    delete input_;
    delete physics_;
    delete graphics_;
}