
#include <cassert>
#include <cstdio>

#include <gf/Action.h>
#include <gf/Clock.h>
#include <gf/Color.h>
#include <gf/EntityContainer.h>
#include <gf/Event.h>
#include <gf/Log.h>
#include <gf/RenderWindow.h>
#include <gf/ResourceManager.h>
#include <gf/ViewContainer.h>
#include <gf/Views.h>
#include <gf/Window.h>
#include <gf/Shapes.h>
#include <gf/Vector.h>

#include "local/Level.h"
#include "local/GameObject.h"

#include "local/CarrePhysicsComponent.h"
#include "local/CarreGraphicsComponent.h"
#include "local/CarreInputComponent.h"

#include "config.h"

//#include <Box2D/Box2D.h>
//#include <cstdio>

int main(/*int argc, char** argv*/) {
    
    gf::Font font;
    font.loadFromFile("data/ClearSans-Bold.ttf");
    
    gf::Clock clock;
    
    
    Level level;
    Graphics graphicsG;
    gf::Event event;
    
    CarreInputComponent* input = new CarreInputComponent(event);
    CarrePhysicsComponent* physics = new CarrePhysicsComponent();
    CarreGraphicsComponent* graphicsComp = new CarreGraphicsComponent();
    
    
    gf::Vector2f position(0,0);
    
    GameObject carre(input, physics, graphicsComp, position, 100.0f, gf::Color::Red);
    
    // game loop
    while (true) {
        // 1. input
        
        
        
        // 2. update
        
        float dt = clock.restart().asSeconds();
        carre.update(level, graphicsG);
        
        // 3. draw
        
        //renderer.clear();
        
        //carre.render(renderer);
        
        graphicsG.display();
        
        
    }
    
    
    return 0;
}
