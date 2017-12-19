#ifndef _GRAPHICS_H
#define _GRAPHICS_H


#include "GameObject.h"
#include "Graphics.h"

class CarreGraphicsComponent : public PhysicsComponent
{
public:
	void update(Carre& carre, Graphics& graphics){
		Shape* shape;
		graphics.draw(*shape, obj.x, obj.y);
	}
}