#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int isPrime(int p) {
        vector<int> fc;

        if (p < 2) {
            cout << p << " is not a prime number." << endl;
            return 0;
        }

        for (int j = p - 1; j >= 2; j--) {
            if (p % j == 0)
                fc.push_back(j);
        }

        if (fc.empty()) {
            cout << p << " is a prime number." << endl;
            return 1;
        }

        cout << p << " is not a prime number, with its factors being 1, " << p;
        for (int i = 0; i < fc.size(); i++)
            cout << ", " << fc[i];
        cout << endl;

        return 0;
    }

    int Factorial(int t) {
        unsigned long long fact = 1; //because int can overflow quickly

        for (int i = 1; i <= t; i++)
            fact *= i;

        cout << "Factorial of " << t << " = " << fact << endl;
        return 1;
    }
};

int main() {
    Solution Solver;

    int a, b, c;

    cout << "Enter 1st number: ";
    cin >> a;

    Solver.isPrime(a);
    Solver.Factorial(a);

    cout << "Enter 2nd number greater than 1st number: ";
    cin >> b;

    Solver.isPrime(b);
    Solver.Factorial(b);

    c = b - a;

    cout << "Difference = " << c << endl;

    Solver.isPrime(c);
    Solver.Factorial(c);

    return 0;
}
/* Here I had a doubt, that why I needed to give 'return 0' and 'return 1' here,
cause last time while doing this same pgoram without functions, I didn't need to.
Here is the answer what I got:
This program doesn't need a return 1; 
because all of the prime-checking code is written directly inside int main(), 
rather than inside a custom function.The rule for return statements in C++ depends entirely
 on whether code is inside main() or inside a regular function.
 Here is the exact breakdown:1. main() has a special exception in C++In C++, 
 the main() function is unique. If execution reaches the very end of main() 
 (the closing brace }) without hitting a return statement, 
 the C++ standard guarantees that the compiler will automatically insert return 0; 
 for you.Because your if(fc.empty()) and else blocks are sitting directly inside main(), 
 the program safely finishes, automatically returns 0 to the operating system, 
 and exits cleanly.
 2. Custom functions do not get this exception
 When you wrote your code inside int isPrime(int p), you created a custom member function. 
 The compiler will not automatically insert a return statement for custom functions.
 If a custom function says it returns an int, you must explicitly write a return 
 statement for every possible path. If you do not, the compiler flags it with the 
 "control reaches end of non-void function" warning you saw earlier.
 ..
*/