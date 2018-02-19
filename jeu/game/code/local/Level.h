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

#define GRAVITY 200.0f

#define SIZE_OF_A_TILE 21
#define TILESET_SPACING 2
#define TILESET_MARGIN 2

#define NB_ROOMS_X 10           //nb de rooms max en x et y
#define NB_ROOMS_Y 10
#define SIZE_ROOM_X 20          //taille d'une room en tuiles
#define SIZE_ROOM_Y 18
#define SIZE_ROOM_X_px (SIZE_ROOM_X*SIZE_OF_A_TILE) //taille d'une room en pixels
#define SIZE_ROOM_Y_px (SIZE_ROOM_Y*SIZE_OF_A_TILE)

#define NUMBER_OF_TILES_X ((NB_ROOMS_X+1)*SIZE_ROOM_X)
#define NUMBER_OF_TILES_Y ((NB_ROOMS_Y+1)*SIZE_ROOM_Y)

#define JUMP_WIDTH_MAX      5   //longueur maximale parcourue par un saut en tuiles (pour génération)
#define JUMP_HEIGHT_MAX     4   //hauteur
#define JUMP_DISTANCE_MAX   8        //sqrt(JUMP_WIDTH_MAX*JUMP_HEIGHT_MAX)

enum{
    UP, RIGHT, DOWN, LEFT
};

class GameObject;
class Graphics;
class ContactListener;

struct roomstruct{
    bool wall[4] = {true,true,true,true};
    bool generated = false;
    int next_room = -1;
    int number = -1;
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
    void placeWalls();
    void placePlatforms();
    gf::Vector2f placePlatform(unsigned int x_start, unsigned int y_start, unsigned int x_dest, unsigned int y_dest, int room_x, int room_y);
    
    std::vector<GameObject> listGameObjects;
    unsigned int nb_objects;
    Graphics* graphicsG;
    
    ContactListener *contactListener;
    gf::TileLayer *tileLayer;
    b2Body* tilePhysicBody;
    gf::Sprite background;
    //gf::RenderStates *bgRenderState;
    b2Vec2 gravity;
    b2Body *tileBody;
    b2BodyDef tileBodyDef;
    
    gf::Array2D<roomstruct> rooms;
};




#endif
