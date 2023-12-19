#pragma once

#include "GameObj.hpp"
#include "Player.hpp"

class Coin: public GameObject {
    protected:
    static int coinCounter;  

    public:
    Coin(int x, int y, SDL_Texture* c_tex);
    static void ResetCoinCounter();
    static int GetCoinCounter();
    void increaseCoinCounter();
    
};


class ff_coin: public Coin{
    public:
    ff_coin(int x, int y, SDL_Texture* c_tex): Coin(x, y, c_tex){}
    void Collision(Player* player);
};

class ww_coin: public Coin{
    public:
    ww_coin(int x, int y, SDL_Texture* c_tex): Coin(x, y, c_tex){}
};