#include "Coin.hpp"


Coin::Coin(int x, int y, SDL_Texture* c_tex):GameObject(x,y,c_tex){}

// int Coin::coinCounter = 0;

void Coin::increaseCoinCounter() {
    coinCounter++;
}

int Coin::GetCoinCounter() {
    return coinCounter;
}

void Coin::ResetCoinCounter() {
    coinCounter = 0;
}
WaterCoin::WaterCoin(int x, int y, SDL_Texture* c_tex):Coin(x,y,c_tex){}

// int WaterCoin::coinCounter = 0;

void WaterCoin::increaseCoinCounter() {
    coinCounter++;
}

int WaterCoin::GetCoinCounter() {
    return coinCounter;
}

void WaterCoin::ResetCoinCounter() {
    coinCounter = 0;
}


FireCoin::FireCoin(int x, int y, SDL_Texture* c_tex): Coin(x,y,c_tex){}

// int WaterCoin::coinCounter = 0;

void FireCoin::increaseCoinCounter() {
    coinCounter++;
}

int FireCoin::GetCoinCounter() {
    return coinCounter;
}

void FireCoin::ResetCoinCounter() {
    coinCounter = 0;
}



