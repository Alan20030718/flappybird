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
    std::vector<Bird> players;

    Texture birdTexture;
    Sprite sprite_bg;
    int sp;
    Texture texture_bg;
public:
    Game(RenderWindow* window);
    bool gameOver = false;
    virtual ~Game();
    void Update();
    void Draw();
    void reset();
    //accessors
    inline RenderWindow& getWindow() {
        return *this->window;
    }
};

