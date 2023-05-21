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
        Parsing _parsing;
        std::vector<double> _lanesX;
        string _levelMusic;
        unsigned int _linesCpt;
        bool _sceneRunning;
        unsigned int _clock;

    public:
        Scene(string configFile, shared_ptr<SFML> sfml);
        ~Scene();
        void startLevel(string configFile, shared_ptr<SFML> sfml);
        void updateFromFile();
        void updateDisplay();
        void loop();
        int endLevel();
};

#endif /* SCENE_HPP_ */