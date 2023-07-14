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
    
   
    
    this->players.push_back(Bird(&birdTexture));
    
}

Game::~Game()
{

}

void Game::Update() 
{
    for (int i = 0; i < players.size(); i++)
    {
        this->players[i].Update();
    }
   
   // for (int i = 0; i < pipes.size(); i++) {
    //    this->pipes[i].Update();
    //}
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
