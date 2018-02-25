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
    input_->initialize(*this, &level, &graphics);
    physics_->initialize(*this, &level);
    graphics_->initialize(*this, &graphics);
}

void GameObject::update(){
    printf("0\n");
    input_->update(*this);
    printf("1\n");
    physics_->update(*this);
    printf("2\n");
    graphics_->update(*this);
    printf("3\n");
}


void GameObject::updateGraphics(){
    graphics_->update(*this);
}

GameObject::~GameObject(){
    delete input_;
    delete physics_;
    delete graphics_;
}