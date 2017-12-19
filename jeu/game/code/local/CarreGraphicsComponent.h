#ifndef _CARREGRAPHICSC_H
#define _CARREGRAPHICSC_H


#include "GameObject.h"
#include "Graphics.h"

#include <gf/Shapes.h>
#include <gf/Event.h>
#include <gf/Shapes.h>
#include <gf/Vector.h>

class CarreGraphicsComponent : public GraphicsComponent
{
public:
	void update(GameObject& obj, Graphics *graphics){
		gf::Shape *shape;
		graphics->draw(shape);
	}
};

#endif