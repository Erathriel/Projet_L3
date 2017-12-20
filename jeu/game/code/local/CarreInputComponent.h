//
// Created by antoine on 19/12/17.
//

#include "InputComponent.h"

extern gf::Window *m_window;

class CarreInputComponent : public InputComponent
{
public:

    ~CarreInputComponent(){}
    void update(GameObject& gb, Level *level)
    {
        
        while (m_window->pollEvent(event)) {
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
        
        if(up_pressed)
            gb.m_position.y -= 100.0f * level->getdt();
        if(down_pressed)
            gb.m_position.y += 100.0f * level->getdt();
        if(left_pressed)
            gb.m_position.x -= 100.0f * level->getdt();
        if(right_pressed)
            gb.m_position.x += 100.0f * level->getdt();

    }
private:
    gf::Event event;
    
    bool up_pressed;
    bool down_pressed;
    bool right_pressed;
    bool left_pressed;

};
