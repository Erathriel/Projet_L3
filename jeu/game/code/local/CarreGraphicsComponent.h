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
            printf("A\n");
            if(!initialised){
		shape = new gf::RectangleShape({obj.m_size,obj.m_size});
                shape->setPosition(obj.m_position);
                shape->setColor(obj.m_color);
                initialised = true;
            }
            printf("B\n");
            graphics->draw(shape);
            printf("C\n");
	}
	~CarreGraphicsComponent(){}
	
private:
        bool initialised = false;
	gf::RectangleShape *shape;
};

#endif