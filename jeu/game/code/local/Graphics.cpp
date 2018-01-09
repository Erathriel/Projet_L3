#include <gf/Sprite.h>
#include "Graphics.h"

class GameObject;


Graphics::Graphics(gf::Vector2u screenSize){
    m_window = new gf::Window("le jeu", screenSize);
    m_renderer = new gf::RenderWindow(*m_window);
    m_view = new gf::View;
    
    m_renderer->clear(gf::Color::White);
    
    m_view->reset({ 0.0f, 0.0f, (float)screenSize.x, (float)screenSize.y });
    m_renderer->setView(*m_view);
    
    
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

void Graphics::draw(gf::RectangleShape* shape){   m_renderer->draw(*shape);      }
void Graphics::draw(GameObject obj){              obj.update(*this);             }
void Graphics::draw(gf::TileLayer* tileLayer){    m_renderer->draw(*tileLayer);  }

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

void Graphics::setViewCenter(gf::Vector2f center){
    m_view->setCenter(center);
    m_renderer->setView(*m_view);
}




