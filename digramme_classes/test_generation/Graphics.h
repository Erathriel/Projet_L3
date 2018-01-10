#ifndef _GRAPHICS_H
#define _GRAPHICS_H


#include "GameObject.h"
#include <gf/RenderWindow.h>
#include <gf/RenderWindow.h>
#include <gf/ResourceManager.h>
#include <gf/ViewContainer.h>
#include <gf/Views.h>
#include <gf/Window.h>
#include <gf/Color.h>
#include <gf/Shapes.h>
#include <gf/Shape.h>
#include <gf/Sprite.h>
#include <gf/Vector.h>
#include <gf/TileLayer.h>

#define TILESET_FILE_NAME "data/spritesheet.png"
#define BACKGROUND_FILE_NAME "data/backgrounds.png"

class GameObject;

class Graphics {
public:
    Graphics(gf::Vector2u screenSize);
    void display();
    void update(GameObject obj);
    void draw(gf::RectangleShape* shape);
    void draw(GameObject obj);
    void draw(gf::TileLayer* tileLayer);
    void draw(gf::Sprite* spr, gf::RenderStates *states = nullptr);
    void setViewCenter(gf::Vector2f center);
    
    gf::Texture* getTileTexture();
    gf::Texture* getBGTexture();
    gf::Window *m_window;
private:
    gf::RenderWindow *m_renderer;
    gf::View *m_view;
    gf::Texture *tileTexture;
    gf::Texture *bgTexture;
    
};
#endif
