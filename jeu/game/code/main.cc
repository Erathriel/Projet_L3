
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
#include "local/Object.h"

#include "config.h"

#include <Box2D/Box2D.h>
#include <cstdio>

int main(/*int argc, char** argv*/) {
    
    static constexpr gf::Vector2u ScreenSize(500, 500);
    gf::Window window("le super exemple", ScreenSize);
    gf::RenderWindow renderer(window);
    
    gf::Font font;
    font.loadFromFile("data/ClearSans-Bold.ttf");
    
    gf::Clock clock;
    renderer.clear(gf::Color::White);

    
    Object carre(ScreenSize / 2, 50.0f, "data/bomb.png");
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
    
    /*B2_NOT_USED(argc);
	B2_NOT_USED(argv);

	// Define the gravity vector.
	b2Vec2 gravity(0.0f, -10.0f);

	// Do we want to let bodies sleep?
	bool doSleep = true;

	// Construct a world object, which will hold and simulate the rigid bodies.
	b2World world(gravity, doSleep);

	// Define the ground body.
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0.0f, -10.0f);

	// Call the body factory which allocates memory for the ground body
	// from a pool and creates the ground box shape (also from a pool).
	// The body is also added to the world.
	b2Body* groundBody = world.CreateBody(&groundBodyDef);

	// Define the ground box shape.
	b2PolygonShape groundBox;

	// The extents are the half-widths of the box.
	groundBox.SetAsBox(50.0f, 10.0f);

	// Add the ground fixture to the ground body.
	groundBody->CreateFixture(&groundBox, 0.0f);

	// Define the dynamic body. We set its position and call the body factory.
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(0.0f, 4.0f);
	b2Body* body = world.CreateBody(&bodyDef);

	// Define another box shape for our dynamic body.
	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(1.0f, 1.0f);

	// Define the dynamic body fixture.
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;

	// Set the box density to be non-zero, so it will be dynamic.
	fixtureDef.density = 1.0f;

	// Override the default friction.
	fixtureDef.friction = 0.3f;

	// Add the shape to the body.
	body->CreateFixture(&fixtureDef);

	// Prepare for simulation. Typically we use a time step of 1/60 of a
	// second (60Hz) and 10 iterations. This provides a high quality simulation
	// in most game scenarios.
	float32 timeStep = 1.0f / 60.0f;
	int32 velocityIterations = 6;
	int32 positionIterations = 2;

	// This is our little game loop.
	for (int32 i = 0; i < 60; ++i)
	{
		// Instruct the world to perform a single step of simulation.
		// It is generally best to keep the time step and iterations fixed.
		world.Step(timeStep, velocityIterations, positionIterations);

		// Clear applied body forces. We didn't apply any forces, but you
		// should know about this function.
		world.ClearForces();

		// Now print the position and angle of the body.
		b2Vec2 position = body->GetPosition();
		float32 angle = body->GetAngle();

		printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
	}

	// When the world destructor is called, all bodies and joints are freed. This can
	// create orphaned pointers, so be careful about your world management.
    
    
    */
    
    return 0;
}
