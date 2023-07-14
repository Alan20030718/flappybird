#include "Bird.h"
#include "Game.h"
using namespace sf;
unsigned Bird::playerNr = 0;
bool gameOver = false;
double bird_movement = 0;
bool gameActive = false;
Bird::Bird(Texture* texture, int UP)
    :level(1), score(0), hp(3)
{
    this->texture = texture;
    this->sprite.setTexture(*this->texture);
    this->sprite.setScale(2.5, 2.5);
    this->sprite.setPosition(125, 490);
    Bird::playerNr++;
    this->playerNumber = Bird::playerNr;
}

Bird::~Bird() {
}

void Bird::Update() {
    this->Movement();
}

void Bird::Draw(RenderTarget& target) {
   
    //target.draw(this->sprite);
    sf::Vector2f targetSize(576.0f, 1024.0f);


    //this->sprite_bg.setScale(
        //targetSize.x / this->sprite_bg.getLocalBounds().width,
        //targetSize.y / this->sprite_bg.getLocalBounds().height);
    target.draw(this->sprite);
}
void Bird::reset()
{
    this->sprite.setPosition(125, 490);
}
void Bird::Movement() {
    bird_movement += 0.75;
    this->sprite.move(0.0f, bird_movement);
    //std::cout << sprite.getPosition().y;
    if (sprite.getPosition().y < 1.25 || sprite.getPosition().y >850) {
        gameOver = true;
        gameActive = false;
    }
    //if (gameActive) {
     //   std::cout << "gameActive" << "\n";
    //}
    
}