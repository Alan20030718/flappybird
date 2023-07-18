#include "Game.h"
#include "Bird.h"
#include "Pipe.h"
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <SFML\System.hpp>
#include <iostream>
#include <vector>
#include <windows.h>
#define PIPE_FREQ 2.0f


using namespace sf;
extern bool gameOver;
extern double bird_movement;
extern bool gameActive;
extern std::vector<std::pair<Sprite, Sprite>> PIPE;
Texture bg;
Texture bg_start;
Texture base;
Texture pipe_top, pipe_bot;


int main()
{
    Clock clock;
    std::srand(std::time(0));
    RenderWindow window(VideoMode(576, 1000), "Bird Game Alan");

    //Sprites and textures of base UI
    pipe_top.loadFromFile("Textures/pipe-green-r.png");
    pipe_bot.loadFromFile("Textures/pipe-green.png");
    bg.loadFromFile("Textures/background-day.png");
    bg_start.loadFromFile("Textures/message.png");
    base.loadFromFile("Textures/base.png");
    Sprite bgs(bg), bg_starts(bg_start), base_s(base);
    bgs.setScale(2, 2);
    bg_starts.setPosition(100, 300);
    bg_starts.setScale(2, 2);
    base_s.setPosition(0, 850);
    base_s.setScale(8, 2);
    Pipe pipe;
   
    Game Game(&window);
    window.setKeyRepeatEnabled(false);

    while (window.isOpen()) 
    {
        window.clear();
        window.draw(bgs);
        window.draw(base_s);
        Event event;
        if (!gameActive) {
            window.draw(bg_starts);
            window.display();
        }
        if (Keyboard::isKeyPressed(Keyboard::Space)) {
            gameActive = true;
        }
        //user interactions
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
                window.close();
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Space && gameActive) {
                //movement is changing  
                bird_movement = 0;
                bird_movement -= 12;
            }
            if (window.getSize().x != 576 || window.getSize().y != 1000) {
                window.setSize(sf::Vector2u(576, 1000));
            }
            if (gameOver) {
                PIPE.clear();
                if (Keyboard::isKeyPressed(Keyboard::Space)) {
                    Game.reset();
                    gameOver = false;
                    gameActive = true;
                }  
            } 
        }
        //draw game components while game is live
        if (gameActive) {
            if (clock.getElapsedTime().asSeconds() >= PIPE_FREQ) {
                pipe.createPipe(&pipe_top, &pipe_bot);
                clock.restart();
            }
            pipe.DrawPipe(window);
            pipe.updatePipe();
            Game.Update();
            Game.Draw();
            window.display();
        }
        //draw & update scores
        
    }
    return 0;
}
