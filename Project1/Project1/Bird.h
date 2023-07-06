#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <iostream>


using namespace sf;

class Bird
{
private:
    Sprite sprite;
    Texture* texture;
    RectangleShape hitBox;
    int level; 
    int score;
    int hp;

public:
    //Bird(Texture* texture);
    //constructor for other control
    Bird(Texture* texture, int UP = 57);
    virtual ~Bird();
    void Update();
    void Movement();
    void Draw(RenderTarget& target);
    //accessors

};
