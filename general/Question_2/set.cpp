// Standard library set class template
#include <iostream>
#include <array>
#include <set>
#include <algorithm> // copy algorithm
#include <iterator> // ostream_iterator & istream_iterator
using namespace std;

/* Question 2: Write function to which, when passed two sorted arrays of integers returns an array of any numbers 
which appear in both*/
/**************************************************************************************************************
Approach: Use set to store unique integers in the array and in this question array class is used because both of
these container classes can work with iterator to loop through element without for loop.
**************************************************************************************************************/

// Function prototype and use template classes for reusability
template <typename T, const size_t SIZE>
void uniqueSet(array<T, SIZE>& arrA, array<T, SIZE>& arrB);

// Input stream operator overloading
template<typename T, const size_t SIZE>
istream& operator>> (istream& in, array<T, SIZE>& arr);

template<typename T>
istream& operator>> (istream& input, T& integer);

// Output stream operator overloading
template<typename T, const size_t SIZE>
ostream& operator<< (ostream& output, array<T, SIZE>& arr);


int main(){
    /* Defined size of array A and B (Arrays are fixed size and therefore it 
    must need to declare constant size). Please change the constant variable to 
    other integer value and scale the size of array*/
    const size_t arrSizeA = 10;
    const size_t arrSizeB = 10;

    // Initialize array A and B
    array<int, arrSizeA> arrayA;
    array<int, arrSizeB> arrayB;

    // Input integer value into array
    cout << "Please insert " << arrSizeA << " integer into array A" << endl;
    cout << "Input format with spacing e.g. 1 2 3 4 5" << endl;
    cin >> arrayA;
    cout << "Array A contains: " << arrayA << endl;

    cout << "Please insert " << arrSizeA << " integer into array B" << endl;
    cout << "Input format with spacing e.g. 1 2 3 4 5" << endl;    
    cin >> arrayB;
    cout << "Array B contains: " << arrayB << endl;

    cout << "Unique set of two array are: " << endl;
    uniqueSet(arrayA, arrayB);

    return 0;
}

/******************************************************************/
// Print the unique set
/******************************************************************/
template <typename T, const size_t SIZE>
void uniqueSet(array<T, SIZE>& arrA, array<T, SIZE>& arrB){
    // less is a built-in function use to sort element
    // Define set to store unique element
    set<T, less<T>> intSet{arrA.begin(), arrA.end()};
    intSet.insert(arrB.begin(), arrB.end());

    // Define output stream to display the set using iterator
    ostream_iterator<T> output{cout, " "};
    
    /* Use copy algorithm combine with ostream to display set without using 
    for loop*/
    copy(intSet.begin(), intSet.end(), output);
}

/******************************************************************/
// Input stream operator overload for user-input array 
/******************************************************************/
template<typename T, const size_t SIZE>
istream& operator>> (istream& input, array<T, SIZE>& arr){
    // Use lambada expression to get input
    for_each(arr.begin(), arr.end(), [&input](auto& elem){input >> elem;});
    return input;
}

/******************************************************************/
// Input stream operator overload for single value integer
/******************************************************************/
template<typename T>
istream& operator>> (istream& input, T& integer){
    input >> integer;
    return input;
}

/******************************************************************/
// Output stream operator overload for display array
/******************************************************************/
template<typename T, const size_t SIZE>
ostream& operator<< (ostream& output, array<T, SIZE>& arr){
    for (auto constIterator = arr.cbegin();            
        constIterator != arr.cend(); ++constIterator) {
        output << *constIterator << ' ';                       
    } 
    return output;
}