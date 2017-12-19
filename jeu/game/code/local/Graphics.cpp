

#include "Graphics.h"

class GameObject;


Graphics::Graphics(){
    static constexpr gf::Vector2u ScreenSize(500, 500);
    gf::Window window("le super exemple", ScreenSize);
    gf::RenderWindow *renderer = new RenderWindow(window);
    m_renderer = renderer;
    m_renderer.clear(gf::Color::White);
}
void Graphics::display(){
    m_renderer.display();
};
void Graphics::draw(void* obj){
    obj.draw(m_renderer);
};
