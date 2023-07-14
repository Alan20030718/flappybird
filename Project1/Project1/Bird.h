#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>

using namespace sf;

class Bird
{
private:
    unsigned playerNumber;
    Sprite sprite;
    Texture* texture;
    Sprite sprite_bg;
    Texture* texture_bg;
    RectangleShape hitBox;
    int level; 
    int hp;
    int score;
    

public:
    //Bird(Texture* texture);
    //constructor for other control
    Bird(Texture* texture, int UP = 57);
    virtual ~Bird();
    void Update();
    void reset();
    void Movement();
    void Draw(RenderTarget& target);
    //accessors
    static unsigned playerNr;
};
