#pragma once

#include "GameObj.hpp"
#include "Player.hpp"

class Coin: public GameObject {
    protected: 
     int coinCounter = 0;  

    public:
    Coin(int x, int y, SDL_Texture* c_tex);
    virtual void ResetCoinCounter();
    virtual int GetCoinCounter();
    void virtual increaseCoinCounter();
    virtual ~Coin() {}
};

class WaterCoin : public Coin{
  private:
    // static int coinCounter;  

    public:
    WaterCoin(int x, int y, SDL_Texture* c_tex); // this construtor should send data to coin 
    
    void ResetCoinCounter() override;
    int GetCoinCounter() override;
    void increaseCoinCounter() override;
};
class FireCoin : public Coin{
  private:
    // static int coinCounter;  

    public:
    FireCoin(int x, int y, SDL_Texture* c_tex); // this construtor should send data to coin 
    
    void ResetCoinCounter() override;
    int GetCoinCounter() override;
    void increaseCoinCounter() override;
};

