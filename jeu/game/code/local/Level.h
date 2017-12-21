#ifndef _LEVEL_H
#define _LEVEL_H


#include "GameObject.h"
#include "Graphics.h"
#include <gf/Window.h>

#define MAX_GAMEOBJECTS 1024

class GameObject;
class Graphics;

class Level {
  private:
    float dt;
    void update(GameObject& obj);
    GameObject *listGameObjects[MAX_GAMEOBJECTS];
    unsigned int nb_objects;
    Graphics* graphicsG;
public:
    Level(Graphics* ngraphicsG);
    gf::Window* getWindow();
    void updateGameObjects(float ndt);
    void addGameObject(GameObject* obj);;
    float getdt();
};
#endif
