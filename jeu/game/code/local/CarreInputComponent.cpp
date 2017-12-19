//
// Created by antoine on 19/12/17.
//

#include "InputComponent.h"
#include <gf/Event.h>


class CarreInputComponent : public InputComponent
{
public:

    CarreInputComponent(gf::Event e) {
        event = e;
    }

    void update(GameObject& gb)
    {
        switch (event.type) {
            case gf::EventType::KeyPressed:
                switch (event.key.keycode) {
                    case gf::Keycode::Up:
                        gb.velocity.y -= 100.0f;
                        break;
                    case gf::Keycode::Down:
                        gb.velocity.y += 100.0f;
                        break;
                    case gf::Keycode::Left:
                        gb.velocity.x -= 100.0f;
                        break;
                    case gf::Keycode::Right:
                        gb.velocity.x += 100.0f;
                        break;
                    default:
                        break;
                }
                break;
            case gf::EventType::KeyReleased:
                switch (event.key.keycode) {
                    case gf::Keycode::Up:
                        gb.velocity.y += 100.0f;
                        break;
                    case gf::Keycode::Down:
                        gb.velocity.y -= 100.0f;
                        break;
                    case gf::Keycode::Left:
                        gb.velocity.x += 100.0f;
                        break;
                    case gf::Keycode::Right:
                        gb.velocity.x -= 100.0f;
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }

    }

};
