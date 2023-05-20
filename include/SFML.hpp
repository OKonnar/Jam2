/*
** EPITECH PROJECT, 2022
** Jam2
** File description:
** SFML.hpp
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class SFML
{
    private:
        sf::Vector2f _size;
        sf::Event _event;
        sf::Window _window;
        sf::Clock _clock;

    public:
        SFML(void);
        ~SFML(void);

        void loop();

        void create();
        void update();
        void display();
        void events();
};
