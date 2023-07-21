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
    Texture pipe_t;
    Sprite pipe_s;
    Texture birdTexture;
    Sprite sprite_bg;
    int sp;
    Texture texture_bg;
    std::vector<Bird> players;
    std::vector<Texture> anim_frame;


public:
    Game(RenderWindow* window);
    bool gameOver = false;
    virtual ~Game();
    void Update();
    void Draw();
    void reset();
    FloatRect get_Bird();
    Vector2f get_Pos();
    void animate();
    //accessors
    inline RenderWindow& getWindow() {
        return *this->window;
    }
};

