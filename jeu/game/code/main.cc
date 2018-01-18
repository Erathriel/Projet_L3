
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

#include "local/CarreGraphicsComponent.h"
#include "local/ProtagInputComponent.h"
#include "local/EmptyInputComponent.h"
#include "local/SpriteGraphicsComponents.h"
#include "local/ProtagGraphicsComponent.h"
#include "local/DynamicPhysicsComponent.h"
#include "local/ProtagPhysicsComponent.h"


#include "local/Level.h"
#include "local/GameObject.h"

#include "config.h"

#include <Box2D/Box2D.h>
#include <cstdio>

int numFootContacts;


int main() {
    
    //gf::Font font;
    //font.loadFromFile("data/ClearSans-Bold.ttf");
    
    // Prepare for simulation. Typically we use a time step of 1/60 of a
    // second (60Hz) and 10 iterations. This provides a high quality simulation
    // in most game scenarios.
    float timeStep = 1.0f / 60.0f;
    float timeStepUs = timeStep *1000000.0f;
    int32 velocityIterations = 8;
    int32 positionIterations = 4;
    
    gf::Clock clock;        //pour calculer dt
    
    static constexpr gf::Vector2u screenSize(500, 500);
    Graphics graphicsG(screenSize);
    Level level(&graphicsG);
    
    //un GameObject a besoin de 3 components, input, physics et graphics
    EmpyInputComponent* input = new EmpyInputComponent();
    DynamicPhysicsComponent* physics = new DynamicPhysicsComponent();
    CarreGraphicsComponent* graphicsComp = new CarreGraphicsComponent();
    
    EmpyInputComponent* input2 = new EmpyInputComponent();
    DynamicPhysicsComponent* physics2 = new DynamicPhysicsComponent();
    SpriteGraphicsComponent* graphicsComp2 = new SpriteGraphicsComponent();
    
    ProtagInputComponent* input3 = new ProtagInputComponent();
    ProtagPhysicsComponent* physics3 = new ProtagPhysicsComponent();
    ProtagGraphicsComponent* graphicsComp3 = new ProtagGraphicsComponent();
    
    
    gf::Vector2f position(1,1);
    
    //on créé un GameObject...
    GameObject carre(input, physics, graphicsComp, position, 100.0f, gf::Color::Red);
    //puis on l'ajoute au niveau
    level.addGameObject(&carre);
    
    GameObject carre2(input2, physics2, graphicsComp2, position*100, 15.0f, gf::Color::Blue);
    level.addGameObject(&carre2);
    
    GameObject sprite1(input3, physics3, graphicsComp3, position*50, 15.0f, gf::Color::Blue);
    level.addGameObject(&sprite1);

    // game loop
    while (true) {
        float dt = clock.restart().asSeconds();
        
        //level demande à tout les objets à la suite de lancer update pour chacun de leur
        //component, il prend dt en paramètre.
        level.updateGameObjects( dt );
        
        level.world->Step( dt, velocityIterations, positionIterations);
        
        //draw
        graphicsG.display();
        
        dt = clock.getElapsedTime().asMicroseconds();
        if( timeStepUs > dt)
            usleep( timeStepUs - dt );
        //printf("%f\n", timeStepUs- dt );
        
    }
    
    
    return 0;
}
