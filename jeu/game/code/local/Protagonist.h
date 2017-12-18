#ifndef _PROTAGONIST_H
#define _PROTAGONIST_H



class Object;

class Protagonist {
  public:
    void controle();


  private:
    int currentAction;


  public:
    void collisions();


  private:
    bool grounded;

    //Camera ;

};
#endif
