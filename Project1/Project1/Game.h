#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Bird.h"
using namespace sf;

class Game
{
private:
    RenderWindow* window;
    Bird* bird;
    Texture birdTexture;
public:
    Game(RenderWindow* window);
    virtual ~Game();
    void Update();
    void Draw();
    //accessors
    inline RenderWindow& getWindow() {
        return *this->window;
    }
};

