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

class Scene
{
    public:
        vector<shared_ptr<Object>> _objects;

    public:
        ~Scene();
        Scene();
        void startLevel(std::string configFile);
        void loop();
        int endLevel();
};

#endif /* SCENE_HPP_ */