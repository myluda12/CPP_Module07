
#pragma once

#include <iostream>

template <typename T>

class Array
{
private:
    unsigned int _size;
    T *arra;

public:
    Array()
    {
        arra = new T;
        _size = 0;
    }
    Array(unsigned int n)
    {
        arra = new T[n];
        _size = n;
    }
    
    Array(Array const &src)
    {
        arra = new T[src._size];
        _size = src._size;
        for (size_t i = 0; i < _size; i++)
            arra[i] = src.arra[i];
    }

    class OutOfRange : public std::exception
    {
        const char *what(void) const throw()
        {
            return "out of range";
        }
    };
    
    unsigned int size(void) const
    {
        return _size;
    }

    T &operator[](unsigned int index)
    {
        if (index >= _size)
            throw OutOfRange();
        return arra[index];
    }

    ~Array()
    {
        _size = 0;
        delete[] arra;
    }
};