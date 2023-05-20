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

#define TILESIZE 400

using namespace std;

class Scene
{
    public:
        vector<shared_ptr<Object>> _objects;
        string _levelMusic;
        unsigned int _bpm;
        shared_ptr<SFML> _sfml;
        vector<sf::Sprite> _sprites;
        vector<sf::RectangleShape> _rectangles;

    public:
        ~Scene();
        Scene();
        void startLevel(string configFile, shared_ptr<SFML> sfml);
        void loop();
        int endLevel();
};

#endif /* SCENE_HPP_ */