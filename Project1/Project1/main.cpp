#include "Game.h"
#include "Bird.h"
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <SFML\System.hpp>
#include <iostream>
using namespace sf;
extern bool gameOver;
extern double bird_movement;
extern bool gameActive;
int main()
{
    bool firstTime = true;
    RenderWindow window(VideoMode(576,1024), "Bird Game Alan");
    Texture bg;
    Texture bg_start;
    bg.loadFromFile("Textures/background-day.png");
    bg_start.loadFromFile("Textures/message.png");
    Sprite bgs;
    Sprite bg_starts(bg_start);
    bgs.setTexture(bg);
    bgs.setScale(2, 2);
    bg_starts.setPosition(100, 300); 
    bg_starts.setScale(2, 2);
    Game Game(&window);
   
    window.setKeyRepeatEnabled(false);
    while (window.isOpen()) {
        window.clear();
        window.draw(bgs);
        //window.draw(bg_starts);
        Event event;
       // if (gameOver)
        //    window.close();
        if (!gameActive) {
            window.draw(bgs);
            window.draw(bg_starts);
            window.display();
        }
        if (Keyboard::isKeyPressed(Keyboard::Space)) {
            gameActive = true;
        }
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
            if (window.getSize().x != 576 || window.getSize().y != 1024) {
                window.setSize(sf::Vector2u(576, 1024));
            }
            //window.clear();

            //window.display();
            if (gameOver) {
                if (Keyboard::isKeyPressed(Keyboard::Space)) {
                    Game.reset();
                    gameOver = false;
                }
                
            }
        }
        //update scores, bird movemnets and something like that
        if (gameActive) {
            Game.Update();

            //window.display();
            Game.Draw();


            window.display();
        }
       
    }

    return 0;
}