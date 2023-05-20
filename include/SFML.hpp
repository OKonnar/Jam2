/*
** EPITECH PROJECT, 2022
** Jam2
** File description:
** SFML.hpp
*/

#pragma once

#include <filesystem>
#include <memory>
#include <map>

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
        sf::Vector2f _size;
        sf::Event _event;
        sf::Window _window;
        sf::Clock _clock;
        std::map<std::string, std::shared_ptr<Sounds>> _sounds;

    public:
        SFML(void);
        ~SFML(void);

        void loop();

        void create();
        void update();
        void display();
        void events();
        void playSoundFromFile(string filepath);
        std::map<std::string, std::shared_ptr<Sounds>> getSounds() {return _sounds;};
        void playSound(string name);
        void loadSounds();
};
