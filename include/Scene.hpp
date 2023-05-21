/*
** EPITECH PROJECT, 2022
** Jam2
** File description:
** Scene.hpp
*/

#pragma once

#ifndef SCENE_HPP_
#define SCENE_HPP_

#include <iostream>
#include <ostream>
#include <memory>
#include <vector>
#include <optional>

#include "Object.hpp"
#include "SFML.hpp"
#include "Parsing.hpp"

#define TILESIZEX 100
#define TILESIZEY 150

using namespace std;

class Scene
{
    private:
        shared_ptr<SFML> _sfml;
        vector<sf::Sprite> _sprites;
        vector<sf::RectangleShape> _rectangles;
        sf::Sprite background;
        sf::Texture backgroundTexture;
        sf::Font font;
        sf::Text sw;
        sf::Text sb;
        Parsing _parsing;
        std::vector<double> _lanesX;
        string _levelMusic;
        unsigned int _linesCpt;
        bool _sceneRunning;
        double _clock;
        int _scoreWhite;
        int _scoreBlack;

    public:
        Scene(string configFile, shared_ptr<SFML> sfml);
        ~Scene();
        bool isNewLine();
        void updateFromFile();
        void updateDisplay();
        void loop();
        std::optional<std::vector<sf::RectangleShape>::iterator> getCollision(sf::Vector2f position);
        void handleEvents();
        int endLevel();
};

#endif /* SCENE_HPP_ */