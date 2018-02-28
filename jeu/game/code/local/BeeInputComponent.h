//
// Created by antoine on 19/12/17.
//

#include "InputComponent.h"


class BeeInputComponent : public InputComponent
{
public:

    ~BeeInputComponent(){}
    void initialize(GameObject& obj, Level *nlevel, Graphics *ngraphics){
        level = nlevel;
        graphics = ngraphics;
    }
    void update(GameObject& gb)
    {
        float velocity = 100000.0f;
        
        if(true)
            gb.m_velocity.y -= velocity * level->getdt();
        if(down_pressed)
            gb.m_velocity.y += velocity * level->getdt();
        if(left_pressed)
            gb.m_velocity.x -= velocity * level->getdt();
        if(right_pressed)
            gb.m_velocity.x += velocity * level->getdt();

    }
private:
    gf::Event event;
    Level *level;
    Graphics *graphics;
    
    bool up_pressed;
    bool down_pressed;
    bool right_pressed;
    bool left_pressed;

};
