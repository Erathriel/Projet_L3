
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
#include <local/SpriteGraphicsComponents.h>

#include "config.h"

//#include <Box2D/Box2D.h>
//#include <cstdio>


int main() {
    
    
    gf::Font font;
    font.loadFromFile("data/ClearSans-Bold.ttf");
    
    gf::Clock clock;
    
    
    Graphics graphicsG;
    Level level(&graphicsG);
    
    CarreInputComponent* input = new CarreInputComponent();
    CarrePhysicsComponent* physics = new CarrePhysicsComponent();
    CarreGraphicsComponent* graphicsComp = new CarreGraphicsComponent();
    CarreInputComponent* input2 = new CarreInputComponent();
    CarrePhysicsComponent* physics2 = new CarrePhysicsComponent();
    CarreGraphicsComponent* graphicsComp2 = new CarreGraphicsComponent();
    CarreInputComponent* input3 = new CarreInputComponent();
    CarrePhysicsComponent* physics3 = new CarrePhysicsComponent();
    SpriteGraphicsComponent* graphicsComp3 = new SpriteGraphicsComponent();
    
    
    gf::Vector2f position(1,1);
    
    GameObject carre(input, physics, graphicsComp, position, 100.0f, gf::Color::Red);
    level.addGameObject(&carre);
    GameObject carre2(input2, physics2, graphicsComp2, position*100, 50.0f, gf::Color::Blue);
    level.addGameObject(&carre2);
    GameObject sprite1(input3, physics3, graphicsComp3, position*50, 25.0f, gf::Color::Blue);
    level.addGameObject(&sprite1);

    
    // game loop
    while (true) {
        
        // 1. input
        // 2. update

        level.updateGameObjects( clock.restart().asSeconds() );
        
        // 3. draw
        
        graphicsG.display();
        
        
    }
    
    
    return 0;
}
