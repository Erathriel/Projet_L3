#ifndef _GRAPHICS_H
#define _GRAPHICS_H


#include "GameObject.h"
#include <gf/RenderWindow.h>
#include <gf/RenderWindow.h>
#include <gf/ResourceManager.h>
#include <gf/ViewContainer.h>
#include <gf/Views.h>
#include <gf/Window.h>

class GameObject;

class Graphics {
public:
    Graphics();
    void display();
    void draw(void* obj);
private:
    gf::RenderWindow *m_renderer;
};
#endif
