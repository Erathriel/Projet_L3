#include "Graphics.h"

class GameObject;

extern gf::Window *m_window;

Graphics::Graphics(){
    static constexpr gf::Vector2u ScreenSize(500, 500);
    m_window = new gf::Window("le super exemple", ScreenSize);
    m_renderer = new gf::RenderWindow(*m_window);
    m_renderer->clear(gf::Color::White);
}

void Graphics::display(){
    m_renderer->display();
    m_renderer->clear();
}

void Graphics::draw(gf::RectangleShape* shape){
    m_renderer->draw(*shape);
}

void Graphics::draw(GameObject obj){
    obj.update(*this);
}

void Graphics::update(GameObject obj){
    obj.update(*this);
}