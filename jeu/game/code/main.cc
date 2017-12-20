
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
    
    printf("0\n");
    
    CarreInputComponent* input = new CarreInputComponent();
    CarrePhysicsComponent* physics = new CarrePhysicsComponent();
    CarreGraphicsComponent* graphicsComp = new CarreGraphicsComponent();
    
    printf("1\n");
    
    gf::Vector2f position(0,0);
    
    GameObject carre(input, physics, graphicsComp, position, 100.0f, gf::Color::Red);
    
    printf("2\n");
    // game loop
    while (true) {
        // 1. input
        
        printf("3\n");
        
        // 2. update
        
        float dt = clock.restart().asSeconds();
        carre.update(level, graphicsG);
        
        printf("4\n");
        // 3. draw
        
        //renderer.clear();
        
        //carre.render(renderer);
        
        graphicsG.display();
        
        printf("5\n");
        
    }
    
    
    return 0;
}
