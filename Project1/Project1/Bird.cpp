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
    //instantiate bird
    this->texture = texture;
    this->sprite.setTexture(*this->texture);
    this->sprite.setScale(2, 2);
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

    target.draw(this->sprite);
}
void Bird::reset()
{
    this->sprite.setPosition(125, 490);
    bird_movement = -10;
}

void Bird::Movement() {
    bird_movement += 0.75;
    this->sprite.move(0.0f, bird_movement);

    /*********** check if bird collides with bounds *********/
    if (sprite.getPosition().y < 1.25 || sprite.getPosition().y >850-sprite.getGlobalBounds().height) {
        gameOver = true;
        gameActive = false;
    }
    
}

FloatRect Bird::get_Loc() 
{
    return this->sprite.getGlobalBounds();
}

Vector2f Bird::get_Pos() 
{
    return this->sprite.getPosition();
}