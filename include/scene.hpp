/*
** EPITECH PROJECT, 2022
** JAM 3
** File description:
** scene.hpp
*/

#ifndef SCENE_HPP_
#define SCENE_HPP_

#include <iostream>
#include <ostream>
#include <memory>
#include <vector>

#include "Object.hpp"

using namespace std;

class Scene
{
    public:
        vector<shared_ptr<Object>> _objects;

    public:
        ~Scene();
        Scene();
};

#endif /* SCENE_HPP_ */