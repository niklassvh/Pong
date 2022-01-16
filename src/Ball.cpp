//
// Created by nikla on 2022-01-14.
//
#include "Ball.h"

Ball::Ball(): startSpeed(1) {
sf::RectangleShape(sf::Vector2f(10,10));
setSize(sf::Vector2f (10,10));
setPosition(400,300);
randomizeDirection();
}


void Ball::bounceX() {
xDirection = - xDirection;

}
void Ball::bounceY() {
yDirection = - yDirection;

}

float Ball::getSpeed() {
return startSpeed;
}


float Ball::getXDirection() {
return xDirection;
}
float Ball::getYDirection() {
return yDirection;
}

void Ball::randomizeDirection() {
    srand(time(NULL));

    if (xDirection = rand() % 2 == 0) {
        xDirection = -1 ;
    } else {
        xDirection = 1;
    }

    if (  yDirection = rand() % 2 == 0){
        yDirection = -1;
    }
    else {
        yDirection = 1;
    }


}

void Ball::recenterAfterPoint() {
    setPosition(400,300);
    startSpeed = 1;
   randomizeDirection();
}

void Ball::increaseSpeed() {
    startSpeed = startSpeed * 1.1;

}






