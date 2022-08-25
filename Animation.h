//
// Created by tim on 8/24/22.
//

#ifndef DODGE_ANIMATION_H
#define DODGE_ANIMATION_H
#include "SFML/Graphics.hpp"

class Animation {
public:
    Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
    void Update(float deltaTime, bool faceRight);

    sf::IntRect uvRect;

private:
    sf::Vector2u imageCount;
    sf::Vector2u currentImage;

    float totalTime;
    float switchTime;

};


#endif //DODGE_ANIMATION_H
