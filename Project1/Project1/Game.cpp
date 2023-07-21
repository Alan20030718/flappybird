#include "Game.h"
#include <iostream>
using namespace sf;
extern bool gameActive;

/*Game::Game(RenderWindow* window)
{   
    this->window = window;
    this->window->setFramerateLimit(60);
    birdTexture.loadFromFile("Textures/bluebird-midflap.png");
    this->players.push_back(Bird(&birdTexture));
}
*/

Game::Game(RenderWindow* window)
{
    this->window = window;
    this->window->setFramerateLimit(60);
    Texture top, mid, bot;
    top.loadFromFile("Textures/bluebird-upflap.png");
    mid.loadFromFile("Textures/bluebird-midflap.png");
    bot.loadFromFile("Textures/bluebird-downflap.png");
    anim_frame.push_back(top);
    anim_frame.push_back(mid);
    anim_frame.push_back(bot);
    this->players.push_back(Bird(&anim_frame));
}

Game::~Game()
{
}

//Update bird
void Game::Update() 
{
    for (int i = 0; i < players.size(); i++)
    {
        this->players[i].Update();
    }
}

//Reset bird when game is over
void Game::reset()
{
    for (int i = 0; i < players.size(); i++)
    {
        this->players[i].reset();
    }
}

//Draw bird
void Game::Draw() 
{
   for (int i = 0; i < players.size(); i++)
   {
       this->players[i].Draw(*this->window);
   }
}

//Get bird local bounds
FloatRect Game::get_Bird()
{
    for (int i = 0; i < players.size(); i++)
    {
        return this->players[i].get_Bound();
    }
}

//Get bird positions
Vector2f Game::get_Pos()
{
    for (int i = 0; i < players.size(); i++)
    {
        return this->players[i].get_Pos();
    }
}

void Game::animate() {
    for (int i = 0; i < players.size(); i++)
    {
        return this->players[i].animate();
    }
}