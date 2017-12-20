//
// Created by antoine on 19/12/17.
//

#include "InputComponent.h"


class CarreInputComponent : public InputComponent
{
public:

    ~CarreInputComponent(){}
    void update(GameObject& gb)
    {
        switch (event.type) {
            case gf::EventType::KeyPressed:
                switch (event.key.keycode) {
                    case gf::Keycode::Up:
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
private:
    gf::Event event;

};
