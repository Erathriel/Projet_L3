//
// Created by antoine on 19/12/17.
//

#include "InputComponent.h"

extern gf::Window *m_window;

class CarreInputComponent : public InputComponent
{
public:

    ~CarreInputComponent(){}
    void update(GameObject& gb)
    {
        //printf("1\n");
        
        while (m_window->pollEvent(event)) {
            switch (event.type) {
                case gf::EventType::Closed:
                    exit(0);
                    break;
                case gf::EventType::KeyPressed:
                    printf("2\n");
                    switch (event.key.keycode) {
                        case gf::Keycode::Up:
                            printf("3\n");
                            gb.m_velocity.y -= 100.0f;
                            break;
                        case gf::Keycode::Down:
                            gb.m_velocity.y += 100.0f;
                            break;
                        case gf::Keycode::Left:
                            gb.m_velocity.x -= 100.0f;
                            break;
                        case gf::Keycode::Right:
                            gb.m_velocity.x += 100.0f;
                            break;
                        default:
                            break;
                    }
                    break;
                case gf::EventType::KeyReleased:
                    switch (event.key.keycode) {
                        case gf::Keycode::Up:
                            gb.m_velocity.y += 100.0f;
                            break;
                        case gf::Keycode::Down:
                            gb.m_velocity.y -= 100.0f;
                            break;
                        case gf::Keycode::Left:
                            gb.m_velocity.x += 100.0f;
                            break;
                        case gf::Keycode::Right:
                            gb.m_velocity.x -= 100.0f;
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
        }

    }
private:
    gf::Event event;

};
