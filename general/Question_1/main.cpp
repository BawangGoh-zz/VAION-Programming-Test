# include <iostream>
# include "fibonacci.h"
using namespace std;

int main(){
    // Test code here
    int x = 0;
    cout << "Input an integer" << endl;
    cin >> x;
    cout << "Testin" << endl;
    
    /* Instantiated fibonacci class (use unsigned long long int because anything lower than this data type
    will cause overflow in the value due to insufficient bytes length) */
    Fibonacci<unsigned long long int> fibo;
    cout << "Even-valued Fibonacci numbers at 100th: " << fibo.even_fibo(x) << endl;
    
    return 0;
}