// Standard library
#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

/* Question 4: Write function to which, when passed a decimal digit X, returns the value
of X+XX+XXX+XXXX*/
/**************************************************************************************************************
Approach: Use the 11 as  e.g. 
32 = contain odd digits (even number)
22 = contain no odd digits (even number)
222221 = contain odd digits (odd number)
223344 = contain odd digits (even number)
In general, even numbers will still contain odd digits but odd numbers will always
return false
**************************************************************************************************************/

// Function prototype
int addRepeatedX(int& x);

int main(){
    int x = 0;
    cout << "Please insert an integer value: " << endl;
    cin >> x;
    cout << addRepeatedX(x) << endl;

    return 0;
}

/******************************************************************/
// Add the repeating sequences
/* Explanation: Use masking array [1, 11, 111, 1111] because 
X*[1, 11, 111, 1111] = [X, XX, XXX, XXXX] and then add all of them.
e.g.
1. 3*[1, 11, 111, 1111] = [3, 33, 333, 3333]
2. 3+33+333+3333 = 3702
/******************************************************************/
int addRepeatedX(int& x){
    const size_t arrSize = 4;
    array <int, arrSize> arrMask{1, 11, 111, 1111};

    int sum = 0;

    // Use lambda expression to perform sum of array with factor X
    for_each(arrMask.begin(), arrMask.end(), [&sum, &x](auto& elem){
        sum += x*elem;
        });

    return sum;
}