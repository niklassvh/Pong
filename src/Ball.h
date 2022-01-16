//
// Created by nikla on 2022-01-14.
//

#ifndef PONGMETODIK_BALL_H
#define PONGMETODIK_BALL_H
#include <SFML/Graphics.hpp>

//! Klassen för bollen som används i spelet. Denna ärver av SFML-bibliotekets rectangleshape
class Ball: public sf::RectangleShape {
public:
    //! default ctor
    Ball();
    //! används för att vända håll på bollen när den slagit i en paddel
    void bounceX();
    //! för att vända håll när bollen slagit i "taket"
    void bounceY();
//! returnerar hastigheten på bollen så att man kan styra detta via Engine.cpp
    float getSpeed();
    //! get X och Y Direction används för att kunna hålla koll på i vilken
    //! riktning bollen är påväg åt. Höger,vänster, upp och ner
    float getXDirection();
    float getYDirection();
    //! används vid start av spelet ochefter någon vunnit poäng. Skickar iväg bollen åt random håll istället för samma riktning varje gång
    void randomizeDirection();
    //! när en spelare tagit poäng så kallas denna på för att centrera bollen i mitten av skärmen igen
    void recenterAfterPoint();
    //! ökar hastigheten på bollen med 0.1 efter varje paddelträff
    void increaseSpeed();
private:
float startSpeed;
float xDirection;
float yDirection;



};


#endif //PONGMETODIK_BALL_H
