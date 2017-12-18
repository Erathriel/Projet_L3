
#include "Object.h"

Object::Object(gf::Vector2f position, float size, const char* imageFile){
    m_position = position;
    m_velocity.x = 0;
    m_velocity.y = 0;
    m_size = size;
        
    // Load a texture from a file
    if (!m_texture.loadFromFile(imageFile))
        imageFile = NULL;               //TODO: log erreur?
    
    gf::Sprite sprite;
    m_sprite = sprite;
    if(imageFile != NULL)
        m_sprite.setTexture(m_texture);
    //m_sprite.setTextureRect({ 0.1f, 0.1f, 0.5f, 0.3f });
    //m_sprite.setAnchor(gf::Anchor::Center);
    //m_sprite.setColor({ 1.0f, 1.0f, 1.0f, 1.0f });
    
}

void Object::setVelocity(gf::Vector2f velocity) {
    m_velocity = velocity;
}

void Object::update(float dt) {
    m_position += dt * m_velocity;
}

void Object::render(gf::RenderTarget& target) {
    m_sprite.setPosition( m_position );
    target.draw(m_sprite);
}