#pragma once
#include <iostream>
#include <vector>
#include <iterator>

// Define Fibonacci class and member function prototype with template class for reusability
template <class T>
class Fibonacci{
    public:
        // Calculate even-valued Fibonacci number
        T even_fibo(int& x);

        // Sum of all element in even value Fibonacci Sequence
        T addFiboVect(const std::vector<T>& fiboVect);

        // Print Fibonacci Sequences (DEBUG PURPOSE)
        void printVector(const std::vector<T>& fiboVect);
        

    private:
        std::vector<T> fiboVect;
        T sum;
};