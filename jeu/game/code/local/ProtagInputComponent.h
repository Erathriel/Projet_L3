//
// Created by antoine on 19/12/17.
//

#include "InputComponent.h"


class ProtagInputComponent : public InputComponent
{
public:

    ~ProtagInputComponent(){}
    void update(GameObject& gb, Level *level)
    {
        
        while (level->getWindow()->pollEvent(event)) {
            switch (event.type) {
                case gf::EventType::Closed:
                    exit(0);
                    break;
                case gf::EventType::KeyPressed:
                    switch (event.key.keycode) {
                        case gf::Keycode::Up:
                            up_pressed = true;
                            break;
                        case gf::Keycode::Down:
                            down_pressed = true;
                            break;
                        case gf::Keycode::Left:
                            
                            left_pressed = true;
                            break;
                        case gf::Keycode::Right:
                            
                            right_pressed = true;
                            break;
                        default:
                            break;
                    }
                    break;
                case gf::EventType::KeyReleased:
                    switch (event.key.keycode) {
                        case gf::Keycode::Up:
                            up_pressed = false;
                            break;
                        case gf::Keycode::Down:
                            down_pressed = false;
                            break;
                        case gf::Keycode::Left:
                            left_pressed = false;
                            break;
                            break;
                        case gf::Keycode::Right:
                            right_pressed = false;
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
        }
        
        float velocity = 3000.0f;
        float jump = 5000.0f;
        if(up_pressed)
            gb.m_velocity.y -= jump * level->getdt();
        //if(down_pressed)
            //gb.m_velocity.y += velocity * level->getdt();
        if(left_pressed)
            gb.m_velocity.x -= velocity * level->getdt();
        if(right_pressed)
            gb.m_velocity.x += velocity * level->getdt();

    }
private:
    gf::Event event;
    
    bool up_pressed;
    bool down_pressed;
    bool right_pressed;
    bool left_pressed;

};
