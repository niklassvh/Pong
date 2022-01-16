//
// Created by nikla on 2022-01-04.
//

#include <iostream>
#include <sstream>
#include "Engine.h"
#include "Paddle.h"



Engine::Engine():resolution(800, 600), p1Score(0), p2Score(0), game_paused(false) {
    window.create(sf::VideoMode(resolution.x, resolution.y), "A game or something");
    window.setFramerateLimit(fps);
}

void Engine::runGame() {
    while(window.isOpen()){
        //! om game_pause flaggan är true, vänta på input.
        while (game_paused)
        {
            input();
        }
        window.clear(sf::Color::Black);
        window.draw(userPaddle);
        window.draw(userPaddleRight);
        window.draw(pongBall);
        ballMovement();
        scoreBoard();
        input();
        //! visa vad som har renderats till main window på skärmen.
        window.display();
    }

}

void Engine::input() {
    sf::Event event{};
    while (window.pollEvent(event)) {
        //! pausar spelet vid tryck på space
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Space) {
              pause();
            }
        }

        if (event.type == sf::Event::Closed) {
            window.close();
        }
        //! stänger av spelet vid tryck på escape
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }
//! överlagrad ++ hos Paddle gör att man kan flytta paddeln uppåt på skärmen
//!  kollar så att paddelns yvärde är större än 0 för att den ska hålla sig inuti rutan
//! Värt att nämna är att x och y-axlarna verkar vara inverterad så 0,0 är högst uppe på skärmen till vänster.*/
        if (event.key.code == sf::Keyboard::W && userPaddle.getPosition().y > 0) {
                ++userPaddle;
        }

        //! här kollar man så att userpaddles y (antar totala längden som då är undersidan om översidan börjar på 0) är mindre än rutans storlek.
        if (event.key.code == sf::Keyboard::S && userPaddle.getPosition().y +userPaddle.getSize().y < window.getSize().y) {
                --userPaddle;
        }
        if (event.key.code == sf::Keyboard::Up && userPaddle.getPosition().y > 0) {
            ++userPaddleRight;
        }
        if (event.key.code == sf::Keyboard::Down && userPaddleRight.getPosition().y +userPaddleRight.getSize().y < window.getSize().y) {
            --userPaddleRight;
        }


    }
}

void Engine::ballMovement() {
    pongBall.setPosition(pongBall.getPosition().x + pongBall.getSpeed() * pongBall.getXDirection(),
                         pongBall.getPosition().y + pongBall.getSpeed() * pongBall.getYDirection());

    //! samma princip som med paddlarna fast för taket och golvet
if( pongBall.getPosition().y <= 0 || pongBall.getPosition().y + pongBall.getSize().y >= window.getSize().y){
    pongBall.bounceY();
}


    if(pongBall.getPosition().x <= userPaddle.getSize().x) {

            if ((pongBall.getPosition().y + pongBall.getSize().y > userPaddle.getPosition().y) &&
                (pongBall.getPosition().y < userPaddle.getPosition().y + userPaddle.getSize().y)) {

                pongBall.bounceX();
                pongBall.increaseSpeed();


        }
            //! när spelare tagit poäng öka poängräknaren och sedan sätt bollen i mitten på skärmen igen
            else{
                p2Score++;
                pongBall.recenterAfterPoint();
            }
    }


//höger paddel
    if(pongBall.getPosition().x + userPaddle.getSize().x >= window.getSize().x - userPaddleRight.getSize().x) {

        if ((pongBall.getPosition().y + pongBall.getSize().y > userPaddleRight.getPosition().y) &&

            (pongBall.getPosition().y < userPaddleRight.getPosition().y + userPaddleRight.getSize().y)) {
            pongBall.bounceX();
            pongBall.increaseSpeed();

        }
        else{
            p1Score++;
            pongBall.recenterAfterPoint();
        }
    }

}

void Engine::scoreBoard() {
//! kollar för error vid inladdning av fonten
    sf::Font font;
    if (!font.loadFromFile("../font/Pacifico.ttf"))
    {
        std::cout << "Error loading font!" << std::endl;
    }

    std::stringstream playerscore;
    sf::Text scoretext;
    playerscore << p1Score << "   -   "<< p2Score;
    scoretext.setString(playerscore.str());
    scoretext.setFont(font);
    scoretext.setCharacterSize(30);
    scoretext.setPosition(350,5);
    scoretext.setFillColor(sf::Color::White);
    window.draw(scoretext);

}

void Engine::pause() {
    std::string ps = "Paused! Press space to resume.";
    sf::Text pause;
    sf::Font pausefont;
    pause.setString(ps);
    pause.setFont(pausefont);
    if (!pausefont.loadFromFile("../font/Pacifico.ttf"))
    {
        std::cout << "Error loading font!" << std::endl;
    }
    pause.setCharacterSize(30);
    pause.setPosition(200,200);
    pause.setFillColor(sf::Color::White);
    window.draw(pause);
    if(!game_paused)
        game_paused = true;
    else{
        game_paused = false;
    }

}




















