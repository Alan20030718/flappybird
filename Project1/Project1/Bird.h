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
    unsigned int anim_itor;
    Clock _clock;
    std::vector<Texture> anim_frame;

public:
    Bird(std::vector<Texture>* anim_tex, int UP = 57);
    virtual ~Bird();
    void Update();
    void reset();
    void Movement();
    FloatRect get_Bound();
    Vector2f get_Pos();
    void Draw(RenderTarget& target);
    //accessors
    static unsigned playerNr;
    void animate();
};
