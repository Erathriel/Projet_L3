#ifndef _CARREGRAPHICSC_H
#define _CARREGRAPHICSC_H


#include "GameObject.h"
#include "Graphics.h"

#include <gf/Shapes.h>
#include <gf/Event.h>
#include <gf/Vector.h>
#include <gf/Color.h>

class Graphics;

class CarreGraphicsComponent : public GraphicsComponent
{
public:
        void initialize(GameObject& obj, Graphics *ngraphics){
            graphics = ngraphics;
            shape = new gf::RectangleShape({obj.m_size,obj.m_size});
            shape->setColor(obj.m_color);
        }
    
	void update(GameObject& obj){
            shape->setPosition(obj.m_position);
            
            graphics->draw(shape);
	}
	~CarreGraphicsComponent(){}
	
private:
	gf::RectangleShape *shape;
        Graphics *graphics;
};

#endif