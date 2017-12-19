#ifndef _CARREGRAPHICSC_H
#define _CARREGRAPHICSC_H


#include "GameObject.h"
#include "Graphics.h"

#include <gf/Shapes.h>
#include <gf/Event.h>
#include <gf/Vector.h>

class Graphics;

class CarreGraphicsComponent : public GraphicsComponent
{
public:
	void update(GameObject& obj, Graphics *graphics){
		gf::RectangleShape *shape;
		graphics->draw(shape);
	}
};

#endif