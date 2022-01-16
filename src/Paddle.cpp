//
// Created by nikla on 2022-01-04.
//

#include "Paddle.h"

Paddle::Paddle( float x, float y, float speed) {
   sf::RectangleShape(sf::Vector2f(20, 20)),
   setSize(sf::Vector2f (15,60));
   setFillColor(sf::Color::Yellow);
    setPosition(x,y);
    paddleSpeed = speed;
}
/* y och x skär varandre uppe till höger, så det är inverterat.
 * */
void Paddle::operator++() {
setPosition(getPosition().x, getPosition().y - paddleSpeed);
}

void Paddle::operator--() {
    setPosition(getPosition().x, getPosition().y + paddleSpeed);
}



