
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
#include "local/EmptyInputComponent.h"
#include "local/SpriteGraphicsComponents.h"
#include "local/ProtagGraphicsComponent.h"

#include "config.h"

//#include <Box2D/Box2D.h>
//#include <cstdio>


int main() {
    
    
    gf::Font font;
    font.loadFromFile("data/ClearSans-Bold.ttf");
    
    gf::Clock clock;        //pour calculer dt
    
    static constexpr gf::Vector2u screenSize(500, 500);
    Graphics graphicsG(screenSize);
    Level level(&graphicsG);
    
    //un GameObject a besoin de 3 components, input, physics et graphics
    EmpyInputComponent* input = new EmpyInputComponent();
    CarrePhysicsComponent* physics = new CarrePhysicsComponent();
    CarreGraphicsComponent* graphicsComp = new CarreGraphicsComponent();
    
    EmpyInputComponent* input2 = new EmpyInputComponent();
    CarrePhysicsComponent* physics2 = new CarrePhysicsComponent();
    SpriteGraphicsComponent* graphicsComp2 = new SpriteGraphicsComponent();
    
    CarreInputComponent* input3 = new CarreInputComponent();
    CarrePhysicsComponent* physics3 = new CarrePhysicsComponent();
    ProtagGraphicsComponent* graphicsComp3 = new ProtagGraphicsComponent();
    
    
    gf::Vector2f position(1,1);
    
    //on créé un GameObject...
    GameObject carre(input, physics, graphicsComp, position, 100.0f, gf::Color::Red);
    //puis on l'ajoute au niveau
    level.addGameObject(&carre);
    
    GameObject carre2(input2, physics2, graphicsComp2, position*100, 50.0f, gf::Color::Blue);
    level.addGameObject(&carre2);
    
    GameObject sprite1(input3, physics3, graphicsComp3, position*50, 25.0f, gf::Color::Blue);
    level.addGameObject(&sprite1);

    
    // game loop
    while (true) {
        
        //level demande à tout les objets à la suite de lancer update pour chacun de leur
        //component, il prend dt en paramètre.
        level.updateGameObjects( clock.restart().asSeconds() );
        
        //draw
        graphicsG.display();
        
        
    }
    
    
    return 0;
}
