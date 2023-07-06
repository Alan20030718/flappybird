#include "Game.h"
#include <iostream>
using namespace sf;
Game::Game(RenderWindow* window) 
{
    this->window = window;
    this->window->setFramerateLimit(60);
    birdTexture.loadFromFile("Textures/background-day.png");
    //init bird
    bird = new Bird(&this->birdTexture);
    //bird->Update();
}

Game::~Game() 
{
    delete bird;
}

void Game::Update() 
{
    bird->Update();
}

void Game::Draw() 
{
    window->clear();
    bird->Draw(*window);
    window->display();
}