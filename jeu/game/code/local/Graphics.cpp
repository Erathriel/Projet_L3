#include "Graphics.h"

class GameObject;

Graphics::Graphics(){
    static constexpr gf::Vector2u ScreenSize(500, 500);
    gf::Window window("le super exemple", ScreenSize);
    gf::RenderWindow *m_renderer = new gf::RenderWindow(window);
    m_renderer->clear(gf::Color::White);
}

void Graphics::display(){
    m_renderer->display();
}

void Graphics::draw(gf::RectangleShape* shape){
    m_renderer->draw(*shape);
}

void Graphics::draw(GameObject obj){
    obj.graphics_->update(obj, *this);
}

void Graphics::update(GameObject obj, Graphics graphics){
    obj.graphics_->update(obj, *this);
}