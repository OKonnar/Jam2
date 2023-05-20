/*
** EPITECH PROJECT, 2022
** Jam2
** File description:
** SFML.cpp
*/

#include "../include/SFML.hpp"

using namespace std;

SFML::SFML(void)    {_window.create(sf::VideoMode {1280, 720, 32}, "Jam");}
SFML::~SFML(void)   {}

void SFML::loop(void)
{
    create();
    while (_window.isOpen()) {
        events();
        update();
        display();
    }
}

void SFML::events(void)
{
    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            _window.close();
    }
}

void SFML::create(void)
{
    // creation des sprites
}

void SFML::update(void)
{
     // update des sprites
}

void SFML::display(void)
{
    // display des sprites
    _window.display();
}
