#include "Game.h"
#include <iostream>
using namespace sf;
extern bool gameActive;
Game::Game(RenderWindow* window) 
{   
    //this->sp = sp;
    this->window = window;
    this->window->setFramerateLimit(60);
    birdTexture.loadFromFile("Textures/bluebird-midflap.png");
    //texture_bg.loadFromFile("Textures/background-day.png");
    this->players.push_back(Bird(&birdTexture));
    //bird = new Bird(&this->birdTexture);
    //rd2 = new Bird(&this->birdTexture);
}

Game::~Game() 
{
    //for (int i = 0; i < players.size(); i++)
    //{
       // delete &this->players[i];
    //}
    //delete bird2;
}

void Game::Update() 
{
    for (int i = 0; i < players.size(); i++)
    {
        this->players[i].Update();
    }
   
}

void Game::reset()
{
    for (int i = 0; i < players.size(); i++)
    {
        this->players[i].reset();
    }
}

void Game::Draw() 
{
   //window->clear();
   for (int i = 0; i < players.size(); i++)
   {
       this->players[i].Draw(*this->window);
   }
  // window->display();
}
