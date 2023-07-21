#include "Bird.h"
#include "Game.h"
using namespace sf;
unsigned Bird::playerNr = 0;
bool gameOver = false;
double bird_movement = 0;
bool gameActive = false;
#define BIRD_ANIM 0.4





Bird::Bird(std::vector<Texture>* anim_tex, int UP)
    :level(1), score(0), hp(3)
{
    anim_itor = 0;
    //instantiate bird
    this->anim_frame = *anim_tex;
    this->sprite.setTexture(anim_frame[anim_itor]);
    this->sprite.setScale(2, 2);
    this->sprite.setPosition(125, 490);
    Bird::playerNr++;
    this->playerNumber = Bird::playerNr;
}

Bird::~Bird() {

}

//Bird Update
void Bird::Update() {
    this->animate();
    this->Movement();
}

//Bird Draw
void Bird::Draw(RenderTarget& target) {

    target.draw(this->sprite);
}

//Bird Reset
void Bird::reset()
{
    this->sprite.setPosition(125, 490);
    bird_movement = -10;
}

//Literally: Bird movement
void Bird::Movement() {
    bird_movement += 0.75;
    this->sprite.move(0.0f, bird_movement);

    /*********** check if bird collides with bounds *********/
    if (sprite.getPosition().y < 1.25 || sprite.getPosition().y >850 - sprite.getGlobalBounds().height) {
        gameOver = true;
        gameActive = false;
    }

}
//Get bird bounds
FloatRect Bird::get_Bound()
{
    return this->sprite.getGlobalBounds();
}

//Get bird positions
Vector2f Bird::get_Pos()
{
    return this->sprite.getPosition();
}


//animate
void Bird::animate()
{
    if (_clock.getElapsedTime().asSeconds() > BIRD_ANIM / anim_frame.size()){
        if (anim_itor < anim_frame.size() - 1) {
            anim_itor++;
        }
        else {
            anim_itor = 0;
        }
        sprite.setTexture(anim_frame[anim_itor]);
        _clock.restart();
    }

}