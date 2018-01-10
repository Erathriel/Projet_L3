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

	void update(GameObject& obj, Graphics *graphics){
            if(!initialised){
		shape = new gf::RectangleShape({obj.m_size,obj.m_size});
                shape->setColor(obj.m_color);
                initialised = true;
            }
            shape->setPosition(obj.m_position);
            
            graphics->draw(shape);
	}
	~CarreGraphicsComponent(){}
	
private:
        bool initialised = false;
	gf::RectangleShape *shape;
};

#endif