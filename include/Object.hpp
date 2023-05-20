/*
** EPITECH PROJECT, 2022
** JAM 3
** File description:
** Object.hpp
*/

#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include <iostream>
#include <ostream>
#include <memory>

using namespace std;

class Object
{
    public:
        struct vector {
            int x;
            int y;
        };
        vector _position;
        vector _size;

    public:
        ~Object();
        Object();
};

#endif /* OBJECT_HPP_ */