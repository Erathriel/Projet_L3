
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
    
    
    static constexpr gf::Vector2u ScreenSize(500, 500);
    gf::Window window("le super exemple", ScreenSize);
    gf::RenderWindow renderer(window);
    
    gf::Font font;
    font.loadFromFile("data/ClearSans-Bold.ttf");
    
    gf::Clock clock;
    renderer.clear(gf::Color::White);
    
    Level level;
    Graphics graphicsG;
    gf::Event event;
    
    CarreInputComponent* input;
    CarrePhysicsComponent* physics;
    CarreGraphicsComponent* graphicsComp;
    
    
    gf::Vector2f position(0,0);
    
    GameObject carre(input, physics, graphicsComp, position, ScreenSize / 2, 50.0f, gf::Color::Red);
    
    // game loop
    while (window.isOpen()) {
        // 1. input
        
        
        
        // 2. update
        
        float dt = clock.restart().asSeconds();
        carre.update(level, graphicsG);
        
        // 3. draw
        
        //renderer.clear();
        
        //carre.render(renderer);
        
        renderer.display();
        
        
    }
    
    
    return 0;
}
