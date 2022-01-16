//
// Created by nikla on 2022-01-04.
//

#ifndef PONGMETODIK_PADDLE_H
#define PONGMETODIK_PADDLE_H
#include <SFML/Graphics.hpp>

class Paddle : public sf::RectangleShape{
public:
    //! Konstruktor, tar x och y som bestämmar vart på skärmen paddlarna ska sitta,
    //! samt hastighet för paddlarnas rörelse.
    Paddle( float x, float y, float speed) ;
    //! Gör det möjligt att skriva ++ eller --Paddle för att ändra positionen i Y-led på dom
    void operator ++ ();
    void operator --();

private:
    float paddleSpeed;


};


#endif //PONGMETODIK_PADDLE_H
