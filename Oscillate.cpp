#include "Oscillator.hpp"
#include<iostream>
using namespace std;


void Oscillator::Oscillate()
{
    double time = SDL_GetTicks() / 1000.0;
    double amplitude = 2.75;
    double frequency = 0.25;
    int yOffset = amplitude * std::sin(2 * M_PI * frequency * time); 
    
    setpos(getpos().x,getpos().y + yOffset);


}