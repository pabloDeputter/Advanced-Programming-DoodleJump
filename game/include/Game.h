//
// Created by Pablo Deputter on 14/11/2021.
//

#ifndef ADVANCED_PROGRAMMING_DOODLEJUMP_GAME_H
#define ADVANCED_PROGRAMMING_DOODLEJUMP_GAME_H

#include "AbstractFactory.h"
#include "ConcreteFactory.h"

#include "controller/PlayerController.h"
#include "view/PlayerView.h"

#include "World.h"
#include "util/Camera.h"

#include "util/Stopwatch.h"

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <iostream>

class Game
{
        std::shared_ptr<sf::RenderWindow> mWindow;
        std::shared_ptr<World> mWorld;
        sf::View mView;
        std::shared_ptr<Model::AbstractFactory> mFactory;

public:
        Game();

        void processEvents();

        void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

        void render();

        void run();
};

#endif // ADVANCED_PROGRAMMING_DOODLEJUMP_GAME_H