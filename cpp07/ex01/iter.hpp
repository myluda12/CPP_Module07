
#pragma once

#include <iostream>

template <typename T>
void iter(T *array, size_t len, void(*func)(const T &))
{
    for (size_t i = 0 ; i < len ; i++)
    {
        func(array[i]);
    }
}
