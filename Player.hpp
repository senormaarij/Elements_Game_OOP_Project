#pragma once


#include "MovingObject.hpp"
#include "GameObj.hpp"
#include "Door.hpp"


class Player: public MovingObject {
    public:
    bool fire;
    bool water;
    bool it_is_true=false;
    Player(int x, int y,SDL_Texture* p_tex);
    void MoveRight(std::vector<GameObject*> objects);
    void MoveLeft( std::vector<GameObject*> objects);
    void Jump(std::vector<GameObject*> objects);
    //bool Collision(GameObject*  object);
};
