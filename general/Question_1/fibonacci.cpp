#include "fibonacci.h"

// Question 1: Sum of the first 100 even-valued Fibonacci numbers
/**************************************************************************************************************
Explanation:
- The Fibonacci sequence is defined as a sequence of integers.
e.g. 0, 1(odd), 1(odd), 2(even), 3(odd), 5(odd), 8(even), 13(odd), 21(odd), 34(even), ...
f(0) = 1 , f(1) = 0 + 1 = 1, f(2) = 1 + 1 =2, ..., f(n) = f(n-1) + f(n-2)
- Each even-valued Fibonacci numbers are sum of preceeding two odds Fibonacci numbers.
e.g f(2) = 2, f(5) = 9, f(8) = 34, ... ==> odd + odd = even
- Therefore, even Fibonacci sequence: 0, 2, 8, 34, 144, ....
- Recurrence for Even Fibonacci sequence:
Consider: F_(n-6), F_(n-5), F_(n-4), F_(n-3), F_(n-2), F_(n-1), F_n
F_n = F_(n-1) + F_(n-2)
    = F_(n-2) + F_(n-3) + F_(n-3) + F_(n-4)
    = F_(n-2) + 2F_(n-3) + F_(n-4)
    = F_(n-3) + F_(n-4) + 2F_(n-3) + F_(n-4) 
    = 3F_(n-3) + 2F_(n-4) (Expanding the even term and keep the odd term since every 3rd term are even numebers)
    = 3F_(n-3) + F_(n-4) + F_(n-5) + F_(n-6) (Combine F_(n-4) and F_(n-5))
    = 4F_(n-3) + F_(n-6)
EF_n = 4F_(n-3) + F_(n-6)
     = 4EF_(n-1) + EF_(n-2)
**************************************************************************************************************/

/******************************************************************/
// Find even-valued Fibonacci Number
/******************************************************************/
template <class T>
T Fibonacci<T>::even_fibo(int& x){
    int i = 0;

    // Initialised the seeds 
    T ef1 = 0, ef2 = 2;

    // Even-valued Fibonacci numbers: EF_n = 4EF_(n-1) + EF_(n-2) for n >= 2
    T efn;
    
    // Update the terms 
    /* Notes that using recursive will cause the program stack to allocate too much memory and code will stuck
    because the stack will release until the last number is processed. */
    while(i<x){
        if (i==0)
            efn = 0;
        else if (i==1)
            efn = 2;
        else
            efn = 4*ef2 + ef1;

        fiboVect.push_back(efn);
        ef1 = ef2;
        ef2 = efn;
        i++;
    }

    // DEBUG PURPOSE
    printVector(fiboVect);
    std::cout << "\nVector size " << fiboVect.size() << std::endl;
    std::cout << "Sum of first 100 even-valued Fibonacci numbers: " << addFiboVect(fiboVect) << std::endl;

    return efn;
}

/******************************************************************/
// Add all the even-valued Fibonacci Sequence to Nth terms
/******************************************************************/
template <class T> 
T Fibonacci<T>::addFiboVect(const std::vector<T>& fiboVect){
    T sum = 0;

    // Add all the even element in the vector using iterator
    for (auto constIterator = fiboVect.cbegin();            
        constIterator != fiboVect.cend(); ++constIterator) {
            sum += *constIterator;
    } 

    return sum;
}

/******************************************************************/
// Print all the even-valued Fibonaaci number in the vector
/******************************************************************/
template <class T> 
void Fibonacci<T>::printVector(const std::vector<T>& fiboVect){
    // display vector elements using const_iterator         
    for (auto constIterator = fiboVect.cbegin();            
        constIterator != fiboVect.cend(); ++constIterator) {
        std::cout << *constIterator << ' ';                       
    } 
}

// Explicitly instantiate the template to tell the compiler of the data types
template class Fibonacci<unsigned long long int>;