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
#include <time.h>

#define MAX_GAMEOBJECTS 1024

#define GRAVITY 500.0f

#define NUMBER_OF_TILES_ROWS 30
#define SIZE_OF_A_TILE 21
#define TILESET_SPACING 2
#define TILESET_MARGIN 2

#define NB_ROOMS_X 10           //nb de rooms max en x et y
#define NB_ROOMS_Y 10
#define SIZE_ROOM_X 8          //taille d'une room en tuiles
#define SIZE_ROOM_Y 6

enum{
    UP, RIGHT, DOWN, LEFT
};

class GameObject;
class Graphics;
class ContactListener;

struct roomstruct{
    bool wall[4] = {true};
    bool generated = false;
};

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
    void generateLevel(int nb_rooms);
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
    
    gf::Array2D<roomstruct> rooms;
};




#endif
