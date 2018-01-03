#ifndef _LEVEL_H
#define _LEVEL_H


#include "GameObject.h"
#include "Graphics.h"
#include <gf/Window.h>
#include <gf/TileLayer.h>
#include <gf/Sprite.h>
#include <gf/Rect.h>
#include <gf/RenderStates.h>
#include <Box2D/Box2D.h>

#define MAX_GAMEOBJECTS 1024

#define GRAVITY 10.0f

#define NUMBER_OF_TILES_ROWS 30
#define SIZE_OF_A_TILE 21
#define TILESET_SPACING 2
#define TILESET_MARGIN 2

class GameObject;
class Graphics;
class ContactListener;

class Level {
public:
    Level(Graphics* ngraphicsG);
    gf::Window* getWindow();
    void updateGameObjects(float ndt);
    void addGameObject(GameObject* obj);;
    float getdt();
    
    b2World *world;
private:
    float dt;
    void update(GameObject& obj);
    void placeTiles();
    
    GameObject *listGameObjects[MAX_GAMEOBJECTS];
    unsigned int nb_objects;
    Graphics* graphicsG;
    
    ContactListener *contactListener;
    gf::TileLayer *tileLayer;
    b2Body* tilePhysicBody;
    gf::Sprite *background;
    gf::RenderStates *bgRenderState;
    b2Vec2 *gravity;
};




#endif
