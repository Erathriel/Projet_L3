#include "Graphics.h"

class GameObject;

Graphics::Graphics(){
    static constexpr gf::Vector2u ScreenSize(500, 500);
    m_window = new gf::Window("le super exemple", ScreenSize);
    m_renderer = new gf::RenderWindow(*m_window);
    m_renderer->clear(gf::Color::White);
}

void Graphics::display(){
    m_renderer->display();
}

void Graphics::draw(gf::RectangleShape* shape2){
    gf::RectangleShape *shape = new gf::RectangleShape({100.0f,10.0f});
    shape->setPosition({0.0f,0.0f});
    printf("lol\n");
    m_renderer->draw(*shape);
    printf("mdr\n");
}

void Graphics::draw(GameObject obj){
    obj.update(*this);
}

void Graphics::update(GameObject obj){
    obj.update(*this);
}