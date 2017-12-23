#include <gf/Sprite.h>
#include "Graphics.h"

class GameObject;


Graphics::Graphics(){
    static constexpr gf::Vector2u ScreenSize(500, 500);
    m_window = new gf::Window("le jeu", ScreenSize);
    m_renderer = new gf::RenderWindow(*m_window);
    m_renderer->clear(gf::Color::White);
    
    tileTexture = new gf::Texture;
    if( !tileTexture->loadFromFile(TILESET_FILE_NAME) ){
        exit(1);
    }
    bgTexture = new gf::Texture;
    if( !bgTexture->loadFromFile(BACKGROUND_FILE_NAME) ){
        exit(1);
    }
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

void Graphics::draw(gf::TileLayer* tileLayer){
    m_renderer->draw(*tileLayer);
}

void Graphics::update(GameObject obj){
    obj.update(*this);
}

void Graphics::draw(gf::Sprite* spr, gf::RenderStates *states){
    if(states != nullptr)
        m_renderer->draw(*spr, *states);
    else
        m_renderer->draw(*spr);
}

gf::Texture* Graphics::getTileTexture(){
    return tileTexture;
}

gf::Texture* Graphics::getBGTexture(){
    return bgTexture;
}