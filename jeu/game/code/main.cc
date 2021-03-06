
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
#include "local/BeeGraphicsComponent.h"
#include "local/DynamicPhysicsComponent.h"
#include "local/ProtagPhysicsComponent.h"


#include "local/Level.h"
#include "local/GameObject.h"

#include "config.h"

#include <Box2D/Box2D.h>
#include <cstdio>

int numFootContacts;
int numFootContactsLadder;
bool touchedExit;

GameObject* createProtag(){
    gf::Vector2f position(NB_ROOMS_X/2 * SIZE_ROOM_X_px + SIZE_ROOM_X_px/2,NB_ROOMS_Y/2 * SIZE_ROOM_Y_px + SIZE_ROOM_X_px/2);
    
    return new GameObject(new ProtagInputComponent(),
                          new ProtagPhysicsComponent(),
                          new ProtagGraphicsComponent(),
                          position, 20.0f, gf::Color::Blue
                         );
}




int main() {
    
    gf::Font font;
    char fileName[255];
    sprintf(fileName, "%s/%s", GAME_DATA_DIR, "ClearSans-Bold.ttf" );
    if( !font.loadFromFile(fileName) ){
        exit(1);
    }
    
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
    //EmptyInputComponent* input = new EmptyInputComponent();
    //DynamicPhysicsComponent* physics = new DynamicPhysicsComponent();
    //CarreGraphicsComponent* graphicsComp = new CarreGraphicsComponent();
    
    EmptyInputComponent* input2 = new EmptyInputComponent();
    DynamicPhysicsComponent* physics2 = new DynamicPhysicsComponent();
    BeeGraphicsComponent* graphicsComp2 = new BeeGraphicsComponent();
    
    
    gf::Vector2f position(NB_ROOMS_X/2 * SIZE_ROOM_X_px + SIZE_ROOM_X_px/2,NB_ROOMS_Y/2 * SIZE_ROOM_Y_px + SIZE_ROOM_X_px/2);
    
    //on créé un GameObject...
    //GameObject carre(input, physics, graphicsComp, position, 100.0f, gf::Color::Red);
    //puis on l'ajoute au niveau
    //level.addGameObject(&carre);
    
    
    GameObject carre2(input2, physics2, graphicsComp2, position, 21.0f, gf::Color::Blue);
    level.addGameObject(&carre2);
    // game loop
    while (true) {
        float dt = clock.restart().asSeconds();
        
        //level demande à tout les objets à la suite de lancer update pour chacun de leur
        //component, il prend dt en paramètre.
        level.updateGameObjects( dt );
        level.world->Step( dt*2, velocityIterations, positionIterations);
        //draw
        graphicsG.display();
        dt = clock.getElapsedTime().asMicroseconds();
        if( timeStepUs > dt)
            usleep( timeStepUs - dt );
        //printf("%f\n", timeStepUs- dt );
        
        //level.~Level();
        //printf("lol\n");
    }
    
    
    return 0;
}


