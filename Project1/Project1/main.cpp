#include "Game.h"
#include "Bird.h"
#include "Pipe.h"
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <SFML\System.hpp>
#include <iostream>
#include <vector>
#include <windows.h>
#include <string>
#define PIPE_FREQ 2.5f
/***********  Switch Game Difficulty  ************/


/***********  Global Variables & External Variables  ************/
using namespace sf;
extern bool gameOver;
extern double bird_movement;
extern bool gameActive;
extern std::vector<std::pair<Sprite, Sprite>> PIPE;
extern std::vector<Sprite> PIPE_sc;
Texture bg;
Texture bg_start;
Texture base;
Texture pipe_top, pipe_bot;
Texture Score;
Font font;
bool checkCollide(Game& game);
std::vector<Sprite> land_s;
std::vector<Sprite> bg_s;
bool firstRun = true;
bool score_UP = false;
int h_sc = 0;
int sc;


int main()
{
    Clock clock;
    std::srand(std::time(0));
    RenderWindow window(VideoMode(576, 1000), "Bird Game Alan");
    Game Game(&window);
    

    /***********  Sprites & textures  ************/
    font.loadFromFile("Textures/04B_19.ttf");
    pipe_top.loadFromFile("Textures/pipe-green-r.png");
    pipe_bot.loadFromFile("Textures/pipe-green.png");
    bg.loadFromFile("Textures/background-day.png");
    bg_start.loadFromFile("Textures/message.png");
    base.loadFromFile("Textures/base.png");
    Sprite bgs(bg), bgs2(bg), bg_starts(bg_start), base_s(base), base_s2(base);
    
    
    /***********  Texts & Scores   ***********/
    Text score;
    Text highest_score;
    highest_score.setFont(font);
    score.setFont(font);
    score.setPosition(288, 200);
    highest_score.setPosition(50, 50);
    score.setCharacterSize(50);
    highest_score.setCharacterSize(50);
    score.setString(std::to_string(sc));
    std::string HS = "Highest score: " + std::to_string(h_sc);
    highest_score.setString(HS);
   
    /***********  moving background  ************/
    bgs.setScale(2, 2);
    bgs.setPosition(0, 0);
    bgs2.setScale(2, 2);
    bgs2.setPosition(bgs.getGlobalBounds().width, 0);
    bg_s.push_back(bgs);
    bg_s.push_back(bgs2);
    bg_starts.setPosition(100, 300);
    bg_starts.setScale(2, 2);

    /***********  moving base  ************/
    base_s.setPosition(0, 850);
    base_s.setScale(8, 2);
    base_s2.setPosition(base_s.getGlobalBounds().width, 850);
    base_s2.setScale(8, 2);
    land_s.push_back(base_s);
    land_s.push_back(base_s2);
    Pipe pipe;
    window.setKeyRepeatEnabled(false);
    bool bird_pass_pipe = false;

    /***********  Game Starts  ************/
    while (window.isOpen()) 
    {
        
        if (checkCollide(Game)) {
            gameActive = false;
            gameOver = true;
        }
        
        window.clear();


        /***********  drawing background  ************/
        for (auto i = 0; i < bg_s.size(); i++) {
            float movement = PIPE_FREQ;
            bg_s[i].move(-movement, 0);
            if (bg_s[i].getPosition().x < 0 - bg_s[i].getGlobalBounds().width) {
                Vector2f position(bg_s[i].getGlobalBounds().width-5, 0);
                bg_s[i].setPosition(position);
            }
        }
        for (auto i = 0; i < bg_s.size(); i++) {
            window.draw(bg_s[i]);
        }


        /***********  moving base  ************/
        for (auto i = 0; i < land_s.size(); i++) {
            float movement = PIPE_FREQ;
            land_s[i].move(-movement, 0);
            if (land_s[i].getPosition().x < 0 - land_s[i].getGlobalBounds().width) {
                Vector2f position(land_s[i].getGlobalBounds().width, 850);
                land_s[i].setPosition(position);
            }
        }
        for (auto i = 0; i < land_s.size(); i++) {
            window.draw(land_s[i]);
        }


        /***********  Init Game  ************/
        Event event;
        if (!gameActive) {
            bird_movement = 0;
            window.draw(bg_starts);
            window.display();
            if (Keyboard::isKeyPressed(Keyboard::Space) && firstRun) {
                gameActive = true;
                firstRun = false;
                bird_movement = 0;
            }
        }
        

        /***********  User Input  ************/
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
                window.close();


            /*********** Bird Movemnet  ************/
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Space && gameActive) {
                bird_movement = 0;
                bird_movement -= 10;
            }


            /***********  Constant Res  ************/
            if (window.getSize().x != 576 || window.getSize().y != 1000) {
                window.setSize(sf::Vector2u(576, 1000));
            }


            /***********  Bird "Dies"  ************/
            if (gameOver) {
                /*Updae (Highest) Score*/
                if (sc >= h_sc) h_sc = sc;
                HS = "Highest score: " + std::to_string(h_sc);
                highest_score.setString(HS);
                sc = 0;

                /*Clear up vectors*/
                PIPE.clear();
                PIPE_sc.clear();

                if (Keyboard::isKeyPressed(Keyboard::Space)) {
                    Game.reset();
                    gameOver = false;
                    gameActive = true;
                }  
            } 
        }


        /***********  Drawing Pipes & Bird & Score  ************/
        if (gameActive) {
            if (clock.getElapsedTime().asSeconds() >= PIPE_FREQ) {
                pipe.createPipe(&pipe_top, &pipe_bot);
                clock.restart();
            }
            pipe.DrawPipe(window);
            pipe.updatePipe();
            Game.Update();
            Game.Draw();

            /*** Display Scores ***/
            for (auto i = 0; i<PIPE_sc.size();i++) { 
                if (Game.get_Pos().x > PIPE_sc[i].getPosition().x && !checkCollide(Game)) {
                    sc++;
                    auto itor = PIPE_sc.erase(PIPE_sc.begin() + i);
                    
                }
                
            }
            
            score.setString(std::to_string(sc));
            
            
            window.draw(highest_score);
            window.draw(score);
            window.display();
        }
    }
    return 0;
}



/***********  Check collision between bird & pipe  ************/
bool checkCollide(Game &game) {
    for (int i = 0; i < PIPE.size(); i++) {
        if (game.get_Bird().intersects(PIPE[i].first.getGlobalBounds()) || game.get_Bird().intersects(PIPE[i].second.getGlobalBounds())) {
            return true;
        }
    }
    return false;
}