#include "Bird.h"
Bird::Bird(Texture* texture, int UP)
    :level(1), score(0), hp(3)
{
    this->texture = texture;
    this->sprite.setTexture(*this->texture);


}

Bird::~Bird() {

}

void Bird::Update() {
    this->Movement();
}

void Bird::Draw(RenderTarget& target) {
    //std::cout << "im here" << "\n";
    sf::Vector2f targetSize(900.0f, 1200.0f); 

    this->sprite.setScale(
    targetSize.x / this->sprite.getLocalBounds().width, 
    targetSize.y / this->sprite.getLocalBounds().height);
    target.draw(this->sprite);
}

void Bird::Movement() {
    if (Keyboard::isKeyPressed(Keyboard::Key(Keyboard::Space)))
        std::cout << "Space" << "\n";
}