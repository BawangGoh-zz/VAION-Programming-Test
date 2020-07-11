// Standard library
#include <iostream>
using namespace std;

/* Question 3: Write function to which, when passed a positive integer returns true if 
the representation of that integer contains no odd digits and otherwise return false*/
/**************************************************************************************************************
Approach: Check every digits of the integer if it can be divisible by 2 otherwise it 
contain odd digits in the representation e.g. 
32 = contain odd digits (even number)
22 = contain no odd digits (even number)
222221 = contain odd digits (odd number)
223344 = contain odd digits (even number)
In general, even numbers will still contain odd digits but odd numbers will always
return false
**************************************************************************************************************/

// Function prototype
bool detectOdd(unsigned long long int& x);

int main(){
    unsigned long long int n = 0;
    cout << "Please input an integer value: " << endl;
    cin >> n;
    cout << detectOdd(n);

    return 0;
}


/******************************************************************/
// Count the odd digits by checking each digit is divisible by 2
/* Explanation: Use modulo 10 to basically performed right shift to check
if the digit is divisible by 2 and this process is repeated until the
leftmost digit in the decimal representation but stopped when the digit 
is not divisble 2
e.g.
1. 138 % 10 = 8 (remainder)
2. 8 % 2 = 0
3. 13.8 % 10 = 3.8 (remainder)
4. 3.8 % 2 = 1.8 --> false (odd digit spotted)
/******************************************************************/
bool detectOdd(unsigned long long int& x){
    bool oddFlag = false;

    // Check each digit whether odd or even
    while (x>0){
        unsigned long long int rem = x % 10;
        if (rem % 2 != 0){
            oddFlag = true;
        }

        // Stop the operation if odd is detected
        if (oddFlag){
            cout << "True" << endl;
            return true;
        }
        x /= 10;   
    }

    // No odd digits detected
    cout << "False" << endl;
    return false;
}