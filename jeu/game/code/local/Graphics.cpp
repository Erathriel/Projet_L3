#include "Graphics.h"

class GameObject;


Graphics::Graphics(){
    static constexpr gf::Vector2u ScreenSize(500, 500);
    m_window = new gf::Window("carré rouge vs carré bleu: le retour du tileset", ScreenSize);
    m_renderer = new gf::RenderWindow(*m_window);
    m_renderer->clear(gf::Color::White);
    
    tileTexture = new gf::Texture;
    if( !tileTexture->loadFromFile(TILESET_NAME_FILE) ){
        exit(1);
    }
}

void Graphics::display(){
    m_renderer->display();
}

void Graphics::draw(gf::RectangleShape* shape){
    m_renderer->draw(*shape);
}

void Graphics::draw(GameObject obj){
    obj.update(*this);
}

void Graphics::draw(gf::TileLayer* tileLayer){
    m_renderer->draw(*tileLayer);
}

void Graphics::update(GameObject obj){
    obj.update(*this);
}

gf::Texture* Graphics::getTileTexture(){
    return tileTexture;
}