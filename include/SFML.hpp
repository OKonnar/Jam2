/*
** EPITECH PROJECT, 2022
** Jam2
** File description:
** SFML.hpp
*/

#pragma once

#include <filesystem>
#include <dirent.h>
#include <memory>
#include <map>
#include <cstring>
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

using namespace std;

class SFML
{
    public :
        struct Sounds {
            sf::SoundBuffer buffer;
            sf::Sound sound;
        };

    private:
        struct Vector2u {
            unsigned int x, y;
        };

        Vector2u            _windowSize;
        sf::Event           _event;
        sf::RenderWindow    _window;
        sf::Clock           _clock;
        std::map<std::string, std::shared_ptr<Sounds>> _sounds;
        std::map<std::string, std::shared_ptr<sf::Music>> _musics;

    public:
        SFML(void);
        ~SFML(void);

        void loop();

        sf::Sprite create(std::string filename, sf::Vector2f size, sf::Vector2f position);
        sf::RectangleShape create(sf::Vector2f size, sf::Vector2f position, sf::Color color);

        void updateSprite(sf::Sprite);
        void updateSprite(sf::Sprite, sf::Vector2f newPos);
        void updateSprite(sf::RectangleShape);
        void updateSprite(sf::RectangleShape, sf::Vector2f newPos);

        void clear();
        void display();
        void events();

        //! SOUNDS
        void playSoundFromFile(string filepath);
        std::map<std::string, std::shared_ptr<Sounds>> getSounds() {return _sounds;};
        void playSound(string name);
        void loadSounds();

        //! MUSICS
        void loadMusic(const std::string& filename);
        void playMusic(const std::string& name);
};
