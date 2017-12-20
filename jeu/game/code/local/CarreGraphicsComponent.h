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

	void update(GameObject& obj, Graphics graphics){
            if(!initialised){
		gf::RectangleShape *shape = new gf::RectangleShape({obj.m_size,obj.m_size});
                shape->setPosition(obj.m_position);
                shape->setColor(obj.m_color);
                initialised = true;
            }
                
            graphics.draw(shape);
	}
	~CarreGraphicsComponent(){}
	
private:
        bool initialised = false;
	gf::RectangleShape *shape;
};

#endif