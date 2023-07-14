#include "Game.h"
#include "Bird.h"
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <SFML\System.hpp>
#include <iostream>
#include <vector>
#include <windows.h>
#define PIPE_FREQ 3.0f


using namespace sf;
extern bool gameOver;
extern double bird_movement;
extern bool gameActive;
void createPipe(Texture* texture1, Texture* texture2);
void updatePipe();
std::vector<int> pipeHeight = { 200,400,600 };
void DrawPipe(RenderTarget& target, Sprite& sprite);
std::vector<std::pair<Sprite, Sprite>> PIPE;

int main()
{
    Clock clock;
    std::srand(std::time(0));
    bool firstTime = true;
    RenderWindow window(VideoMode(576, 1000), "Bird Game Alan");
    Texture bg;
    Texture bg_start;
    Texture base;
    Texture pipe_top, pipe_bot;
    pipe_top.loadFromFile("Textures/pipe-green-r.png");
    pipe_bot.loadFromFile("Textures/pipe-green.png");
    bg.loadFromFile("Textures/background-day.png");
    bg_start.loadFromFile("Textures/message.png");
    base.loadFromFile("Textures/base.png");
    Sprite bgs(bg), bg_starts(bg_start), base_s(base);
    bgs.setScale(2, 2);
    bg_starts.setPosition(100, 300);
    bg_starts.setScale(2, 2);
    base_s.setPosition(0, 800);
    base_s.setScale(8, 2);
    //pipes
   
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

       
        if (gameActive) {
            if (clock.getElapsedTime().asSeconds() > PIPE_FREQ) {
                createPipe(&pipe_top, &pipe_bot);
                clock.restart();
            }

            
            for (int i = 0; i < PIPE.size();i++){               //std::cout << "drawing" << "\n";
                DrawPipe(window, PIPE[i].first);
                DrawPipe(window, PIPE[i].second); 
                updatePipe();
            }  
           
            Game.Update();
            Game.Draw();
            window.display();
        }
        //update scores, bird movemnets and something like that
        
    }
    return 0;
}

void createPipe(Texture* texture1, Texture* texture2) {
        int _landHeight = 800;
        //wait_until_next_second();
        Sprite pipe_t(*texture1), pipe_b(*texture2);
        pipe_b.scale(1.5, 1);
        //pipe_t.rotate(180);
        pipe_t.scale(1.5, 1);
        int pipe_Y = (rand() % _landHeight + 1);
        pipe_t.setPosition(576, -pipe_Y);
        pipe_b.setPosition(576, 1000-pipe_b.getGlobalBounds().height - pipe_Y);
        PIPE.push_back(std::make_pair(pipe_t, pipe_b));
        std::cout << PIPE.size() << "\n";
        //clock.restart();
    
}

void updatePipe() {
    for (int i = 0; i < PIPE.size(); i++) {
            PIPE[i].first.move(-5, 0);
            PIPE[i].second.move(-5, 0);
            if (PIPE[i].first.getPosition().x == -600) {
                auto itor = PIPE.erase(PIPE.begin()+i);
        }
    }
    
}

void DrawPipe(RenderTarget& target, Sprite& sprite)
{
    target.draw(sprite);
   // std::cout << "drawing pipes" << "\n";
}