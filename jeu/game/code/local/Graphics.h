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
#include <gf/Vector.h>

class GameObject;

class Graphics {
public:
    Graphics();
    void display();
    void update(GameObject obj);
    void draw(gf::RectangleShape* shape);
    void draw(GameObject obj);
    
    gf::Window *m_window;
private:
    gf::RenderWindow *m_renderer;
    
};
#endif
