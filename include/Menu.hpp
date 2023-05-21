/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Menu.hpp
*/

#ifndef MENU_HPP_
#define MENU_HPP_

#include "Scene.hpp"
#include <filesystem>
#include <fstream>
#include <sstream>

namespace fs = std::filesystem;

class Menu
{
    private:
        shared_ptr<SFML> _sfml;
        vector<sf::RectangleShape> _rectangles;
        bool _screenRunning;
        double _clock;
        int _p;
        sf::Texture _backgroundTexture;
        sf::Sprite _background;
        unsigned short _select;
        bool _release;

    public:
        struct Button {
            sf::RectangleShape rect;
            sf::Font font;
            sf::Text song;
            sf::Text bpm;
            sf::Text duration;
        };
        vector<Button> _buttons;

        struct Info {
            std::string path;
            std::string musicName;
            unsigned int bpm;
            unsigned int duration;
        };
        vector<Info> _infos;

        Menu(shared_ptr<SFML> sfml);
        ~Menu() {};

        int vecLen();
        void initNewButton(Info info);
        std::vector<std::string> getFiles(const std::string &path);
        void getInfos(const std::vector<std::string> &files);
        void unselectedRect();
        void selectedRect();
        void handleEvents();
        void updateDisplay();
        std::string givePath();
        void loop();
};

#endif /* MENU_HPP_ */