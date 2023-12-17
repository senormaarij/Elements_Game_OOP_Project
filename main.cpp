

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "GameObj.hpp"
#include <vector>
#include "RenderWindow.hpp"
#include "Player.hpp"
#include "Coin.hpp"
#include "Door.hpp"
#include "Oscillator.hpp"

float getCurrentTime(){
    return SDL_GetTicks()/1000.0f;
}


int main(int argc, char* args[]){
	if (SDL_Init(SDL_INIT_VIDEO) > 0)
		std::cout << "HEY.. SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl; //flag to check SDL initialized

	srand(time(0));


    /*------------------WINDOW & RENDERER---------------*/
	RenderWindow window("Elements", 800, 600);
	SDL_Renderer* renderer = window.getRenderer();

   
    /*--------------LOAD TEXTURE-----------------*/
    SDL_Texture* p_fire_tex = window.LoadTexture("assets/FireChar.png");
    SDL_Texture* p_water_tex = window.LoadTexture("assets/WaterChar.png");
    SDL_Texture* game_bg = window.LoadTexture("assets/bg.png");
    SDL_Texture* mainscreen = window.LoadTexture("assets/main_screen.png");
    SDL_Texture* border = window.LoadTexture("assets/borders.png");
    SDL_Texture* w_coin = window.LoadTexture("assets/s_jewel.png");
    SDL_Texture* f_coin = window.LoadTexture("assets/f_jewel.png");
    SDL_Texture* platform  = window.LoadTexture("assets/platform.png"); 
    SDL_Texture* top = window.LoadTexture("assets/top_bound.png");
    SDL_Texture* ground = window.LoadTexture("assets/ground.png");
    SDL_Texture* water_platform = window.LoadTexture("assets/water_plat.png");
    SDL_Texture* fire_platform = window.LoadTexture("assets/fire_plat.png");
    SDL_Texture*  s_platform = window.LoadTexture("assets/platform_small.png");
    SDL_Texture*  box = window.LoadTexture("assets/box.png");
    SDL_Texture*  door = window.LoadTexture("assets/door.png");
    SDL_Texture*  f_platform = window.LoadTexture("assets/f_platform.png");
   
    /*-------------INITIALIZE PLAYER & LEVEL VECTORS-------------------*/
    Player player2(50,500,p_water_tex); //player constructor for player 2(always Water Character)
    Player player1(100,500,p_fire_tex); //player constructor for player 1(always Fire Character)


    std::vector<GameObject*> platforms ; //vector of platforms
    std::vector<Coin*> coins ; //vector of coins
    std::vector<Door*> doors ; //vector of doors
    std::vector<GameObject*> firePlatform; //vector of firePlatforms
    std::vector<GameObject*> waterPlatform; //vector of waterPlatforms

  
    GameObject* plat_1 = new GameObject(0,600,ground);
    GameObject* plat_2 = new GameObject(0,400,s_platform);
    GameObject* plat_3 = new GameObject(200,400,s_platform);

    GameObject* plat_4 = new GameObject(400,400,s_platform);
    GameObject* plat_5 = new GameObject(400,275,s_platform);
    GameObject* plat_6 = new GameObject(600,275,s_platform);

    GameObject* plat_7 = new GameObject(200,120,s_platform);
    GameObject* plat_8 = new GameObject(400,120,s_platform);
    GameObject* plat_9 = new GameObject(0,120,s_platform);
    GameObject* plat_10 = new GameObject(200,275,s_platform);

    GameObject* plat_11 = new Oscillator(600,175,s_platform);
    GameObject* plat_12 = new   Oscillator(200,500,f_platform);
   

    GameObject* top1 = new GameObject(0,0,top);
    GameObject* wall1 = new GameObject(0,500,border);
    GameObject* wall2 = new GameObject(800,500,border);

    GameObject* Door1 = new Door(10,100,box);

    GameObject* fireplat_1 = new GameObject(0,500,fire_platform);
    GameObject* fireplat_2 = new GameObject(0,300,fire_platform);
    GameObject* water_plat1 = new GameObject(0,100,water_platform);
    GameObject* water_plat2 = new GameObject(200,100,water_platform);


    Coin* c1 = new Coin(100,450,f_coin);
    Coin* c2 = new Coin(250,450,w_coin);
    Coin* c3 = new Coin(400,450,w_coin);
    Coin* c4 = new Coin(550,450,f_coin);
    Coin* c5 = new Coin(700,450,w_coin);
    Coin* c6 = new Coin(100,250,f_coin);
    Coin* c7 = new Coin(250,250,w_coin);
    Coin* c8 = new Coin(400,250,f_coin);
    Coin* c9 = new Coin(550,250,w_coin);
    Coin* c10 = new Coin(700,250,f_coin);
    Coin* c11 = new Coin(100,50,w_coin);
    Coin* c12 = new Coin(250,50,f_coin);


    /*-------------------INITIALIZING OTHER GAME VALUES--------------------*/
    
    /*-------Game States---------*/
    bool isReset = false ;
    bool isInMenu = true ;// main menu screen is default screen   
    bool isInGame = false;
    bool isWin = false;
    bool isLose = false;

    int totalCoins = 12;
    

    bool gamerun = true; //To run the game 
 
    Screen background(mainscreen);

    SDL_Event event; //to poll events 

    const Uint8* keyboard = SDL_GetKeyboardState(NULL); //Keyboard inputs 

    float currentTime = getCurrentTime();

    /*------GAME LOOP------*/

    while(gamerun){
        currentTime = getCurrentTime();
        if (SDL_PollEvent(&event) && (event.type == SDL_QUIT)){
            gamerun = false;
        }

        if(isInMenu){
            window.clear();
            window.render(background);
            window.display();
        
        if(keyboard[SDL_SCANCODE_SPACE]){
            isInMenu = false;
            isInGame = true;
            background.switch_screen(game_bg);
            }
        } 
        else if(isInGame){
            if(!isReset){
                window.clear();
                window.render(background);

                /*------------------ADDING PLATFORMS-----------------*/
                platforms.push_back(plat_12);
                platforms.push_back(plat_1);
                platforms.push_back(plat_2);
                platforms.push_back(plat_3);
                platforms.push_back(plat_4);
                platforms.push_back(plat_5);
                platforms.push_back(plat_6);
                platforms.push_back(plat_7);
                platforms.push_back(plat_8);
                platforms.push_back(plat_9);
                platforms.push_back(plat_10);
                platforms.push_back(plat_11);
               

                platforms.push_back(top1);
                platforms.push_back(wall1);
                platforms.push_back(wall2);
                
                /*----------------ADDING COINS---------------------*/
                coins.push_back(c1);
                coins.push_back(c2);
                coins.push_back(c3);
                coins.push_back(c4);
                coins.push_back(c5);
                coins.push_back(c6);
                coins.push_back(c7);
                coins.push_back(c8);
                coins.push_back(c9);
                coins.push_back(c10);
                coins.push_back(c11);
                coins.push_back(c12);




                /*----------------INTIALIZING PLAYER LOCATION---------------------*/
                player1.setpos(100,475);
                player2.setpos(50,475);



                
                window.display();

                isReset = true;
            }
            else{
            /*                              HANDLE PLAYER CONTROLS                                     */

				if(keyboard[SDL_SCANCODE_LEFT]){ //player 1 goes left
					player1.MoveLeft(platforms);
				}
				if(keyboard[SDL_SCANCODE_RIGHT]){   //player 1 goes right
					player1.MoveRight(platforms);
                    
				}
                if(keyboard[SDL_SCANCODE_UP]){ //player 1 jumps
                    player1.Jump(platforms);
                }
                if(keyboard[SDL_SCANCODE_A]){ //player 2 goes left
                    player2.MoveLeft(platforms);
                }
                if(keyboard[SDL_SCANCODE_D]){  //player 2 goes right
                    player2.MoveRight(platforms);
                }
                if(keyboard[SDL_SCANCODE_W]){ //player 2 jumps
                    player2.Jump(platforms);
                }
                if(keyboard[SDL_SCANCODE_R]){
                    isReset = false;
                    coins[0]->ResetCoinCounter();
                    platforms.clear();
                    coins.clear();
                }

            }

            /*---------------GAME UPDATES---------------*/
            player1.Gravity(platforms);
            player2.Gravity(platforms);

          

            /*------------COIN HANDLING---------------*/
             for (int i = 0; i < coins.size(); i++) {
                
                if(coins[i]->Collision(&player1) || coins[i]->Collision(&player2)){
                    coins.erase(coins.begin() + i);
                    coins[i]->increaseCoinCounter();
                    std::cout<<coins[i]->GetCoinCounter();
                }
            }

            /*------------WIN---------------*/
            if(coins[0]->GetCoinCounter() == totalCoins){
                isWin = true;
                isInGame = false;
                coins[0]->ResetCoinCounter();

                background.switch_screen(mainscreen);
            }

            

            /*------------Oscillator---------------*/

            Oscillator* o = dynamic_cast<Oscillator*>(plat_11);
            o->Oscillate();
            Oscillator* o2 = dynamic_cast<Oscillator*>(plat_12);
            o2->Oscillate();


            /*-----------------RENDERING ALL THINGS------------------*/
            window.clear();
            window.render(background);
            for (int i = 0; i < platforms.size(); i++) {
                window.render(*platforms[i]);
            }

            for(auto& coin: coins){
                window.render(*coin);
            }
            window.render(player1);
            window.render(player2);
            window.display();
		}
    


        if (isWin) {
         
            if(keyboard[SDL_SCANCODE_R]){
                platforms.clear();
                coins.clear();
                isWin = false;
                isInGame = true;
                isReset = false;
                background.switch_screen(game_bg);
            }
        }
        if (isLose) {
            background.switch_screen(failScreen);
            window.clear();
            window.render(background);
            window.display();
            if(keyboard[SDL_SCANCODE_R]){
                platforms.clear();
                coins.clear();
                isLose = false;
                isInGame = true;
                isReset = false;
                background.switch_screen(game_bg);
            }
        }

    }



	window.cleanUp(); // DELETE EVERYTHING ON SCREEN

	



    /*------------------FREE MEMORY-----------------*/
    // for(int i = 0 ; i < platforms.size(); i ++)
    // {
    //     delete platforms[i];
    //     platforms[i] = nullptr;
    // }

    for(int i = 0; i < coins.size(); i++)
    {
        delete coins[i];
        coins[i] = nullptr;
    }
	
  

	SDL_Quit(); 

    return 0; 
}

