
#include "Object.h"

Object::Object(gf::Vector2f position, float size, gf::Color4f color){
    m_position = position;
    m_velocity.x = 0;
    m_velocity.y = 0;
    m_size = size;
    m_color = color;
}

void Object::setVelocity(gf::Vector2f velocity) {
    m_velocity = velocity;
}

void Object::update(float dt) {
    m_position += dt * m_velocity;
}

void Object::render(gf::RenderTarget& target) {
    gf::RectangleShape shape({ m_size, m_size });
    shape.setPosition(m_position);
    shape.setColor(m_color);
    shape.setAnchor(gf::Anchor::Center);
    target.draw(shape);
}