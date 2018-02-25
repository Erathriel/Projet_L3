//
// Created by antoine on 19/12/17.
//

#include "InputComponent.h"


class EmptyInputComponent : public InputComponent
{
public:

    ~EmptyInputComponent(){}
    void initialize(GameObject& obj, Level *level, Graphics *graphics){
        
    }
    
    void update(GameObject& gb)
    {
        
    }
private:

};
