#include "Game.h"
#include "Bird.h"
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <SFML\System.hpp>
#include <iostream>
using namespace sf;

int main()
{

    RenderWindow window(VideoMode(576,1024), "Bird Game Alan");
    //window.setSize(sf::Vector2u(576, 1024));
    Game Game(&window);
    window.display();
    //sf::Texture texture;
    //texture.loadFromFile("birdgty.png");
    //sf::RectangleShape rectShape(sf::Vector2f(300, 150));
    //rectShape.setTexture(&texture);
 
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
                window.close();
            //window.clear(sf::Color::Black);
            //window.draw(rectShape);
            //window.display();
        }
        if (window.getSize().x != 576 || window.getSize().y != 1024) {
            window.setSize(sf::Vector2u(576, 1024));
        }
        //std::cout<<Keyboard::Space <<std::endl;
        Game.Update();
        Game.Draw();
    }

    return 0;
}