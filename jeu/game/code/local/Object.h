#ifndef _OBJECT_H
#define _OBJECT_H

#include <gf/Color.h>
#include <gf/RenderWindow.h>
#include <gf/Shapes.h>
#include <gf/Vector.h>
#include <gf/Sprite.h>

#include "Level.h"

class Object {
public:
    Object(gf::Vector2f position, float size, const char* imageFile);
    void setVelocity(gf::Vector2f velocity);
    void update(float dt);
    void render(gf::RenderTarget& target);
private:
    gf::Vector2f m_position; // center of the square
    gf::Vector2f m_velocity;
    float m_size;
    gf::Texture m_texture;
    gf::Sprite m_sprite;
};

#endif
