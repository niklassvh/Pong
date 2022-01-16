//
// Created by nikla on 2022-01-04.
//

#ifndef PONGMETODIK_ENGINE_H
#define PONGMETODIK_ENGINE_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics./RectangleShape.hpp>
#include "Paddle.h"
#include "Ball.h"


class Engine {
public:
    //!default ctor. skapar rutan för själva spelet, sätter upplösning, ställer poängen till noll och sätter FPS-gränsen
    Engine();
    //! loopen för sjävla speletspelet. lyssnar efter input, ritar komponenter på skärmen samt kallar på funktionerna
    //! som uppdaterar dessa komponenter*/
    void runGame();
    //! håller reda på poängställning för spelarna
    void scoreBoard();
    //! lyssnar efter användarinput för bla. rörelser av paddlar, pausning av spel eller avstängning av spel
    void input();
    //!sköter hur bollen ska röra sig på själva main rutan. Kollisionshantering mm.
    void ballMovement();
    //! hanteringen av paus. pausar eller avpausar spelet, laddar in typsnitt och skriver ut meddelande på skärmen.
    void pause();

private:
    sf::Vector2f resolution;
    sf::RenderWindow window;
    const int fps = 100;
    Paddle userPaddle{10, 280,12};
    Paddle userPaddleRight{775, 280, 12};
    Ball pongBall;
    int p1Score;
    int p2Score;
    bool game_paused;

};


#endif //PONGMETODIK_ENGINE_H
