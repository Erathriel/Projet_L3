
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

#include "config.h"

//#include <Box2D/Box2D.h>
#include <cstdio>

int main(/*int argc, char** argv*/) {
    
    
    static constexpr gf::Vector2u ScreenSize(500, 500);
    gf::Window window("le super exemple", ScreenSize);
    gf::RenderWindow renderer(window);
    
    gf::Font font;
    font.loadFromFile("data/ClearSans-Bold.ttf");
    
    gf::Clock clock;
    renderer.clear(gf::Color::White);

    
    GameObject carre(ScreenSize / 2, 50.0f, "data/bomb.png");
    static constexpr float Speed = 100.0f;
    gf::Vector2f velocity(0, 0);
    
    // game loop
    while (window.isOpen()) {
        // 1. input
        
        gf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case gf::EventType::Closed:
                window.close();
                break;
                case gf::EventType::KeyPressed:
                    switch (event.key.keycode) {
                    case gf::Keycode::Up:
                        velocity.y -= Speed;
                        break;
                    case gf::Keycode::Down:
                        velocity.y += Speed;
                        break;
                    case gf::Keycode::Left:
                        velocity.x -= Speed;
                        break;
                    case gf::Keycode::Right:
                        velocity.x += Speed;
                        break;
                    default:
                        break;
                    }
                    break;
                case gf::EventType::KeyReleased:
                    switch (event.key.keycode) {
                    case gf::Keycode::Up:
                        velocity.y += Speed;
                        break;
                    case gf::Keycode::Down:
                        velocity.y -= Speed;
                        break;
                    case gf::Keycode::Left:
                        velocity.x += Speed;
                        break;
                    case gf::Keycode::Right:
                        velocity.x -= Speed;
                        break;
                    default:
                        break;
                    }
                    break;
            default:
                break;
            }
        }
        
        
        // 2. update
        
        carre.setVelocity(velocity);
        float dt = clock.restart().asSeconds();
        carre.update(dt);
        
        
        // 3. draw
        
        renderer.clear();
        
        carre.render(renderer);
        
        renderer.display();
        
        
    }
    
    
    return 0;
}
