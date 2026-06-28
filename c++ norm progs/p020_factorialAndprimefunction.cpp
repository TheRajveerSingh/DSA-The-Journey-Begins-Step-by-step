#include <iostream>
#include <vector>
using namespace std;

class Solution { //A class groups related functions together.
public: //Anything below public: can be used outside the class. A 'private' cannot be used outside the class.
    bool isPrime(int p) { 
        vector<int> fc; //Creates an empty vector

        if (p < 2) {
            cout << p << " is not a prime number." << endl;
            return false;
        }

        for (int j = p - 1; j >= 2; j--) {
            if (p % j == 0)
                fc.push_back(j);
        }

        if (fc.empty()) {
            cout << p << " is a prime number." << endl;
            return true;
        }

        cout << p << " is not a prime number, with its factors being 1, " << p;
        for (size_t i = 0; i < fc.size(); i++)
        // Earlier, I used 'int i', but vector.size() actually returns a 'size_t', which is an unsigned
        // integer type used to represent sizes and indexes. Comparing an int (signed) with a size_t
        // (unsigned) may produce compiler warnings because they are different data types. Using
        // 'size_t i' ensures both sides of the comparison are the same type and follows good C++ coding practice.
            cout << ", " << fc[i];
        cout << endl;

        return false;
    }

    void Factorial(int t) { 
    // Earlier, this function returned int.
    // Since it only prints the factorial and doesn't return a value,
    // its return type has been changed to 'void'.
        unsigned long long fact = 1; //because int can overflow quickly, and Factorials become huge.

        for (int i = 1; i <= t; i++)
            fact *= i;

        cout << "Factorial of " << t << " = " << fact << endl;
       // Here, earlier I had written 'return 1;' but now, I've removed it as function is now 'void', and actually we don't need to return anything.
    }
};
int main() {
    Solution Solver; //solver is an object 

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
//When to use 'return' ?
/* 
Here,
Factorial() only performs a task (prints the factorial), so it doesn't need to return anything.
isPrime() answers a question ("Is this number prime?"), so returning true or false makes sense.
...but then, we are calling it as "Solver.isPrime(a);", we're ignoring the returned value,
just like we were ignoring return 1; in Factorial() earlier.
So the question comes up:
If I'm ignoring it anyway, why not make isPrime() also void?
....
Answer: Because isPrime() is designed to give an answer.
Simple Logic:
Does a function only print something, or calculate something which needs to be used later?
Prime is stored as true or false, and then might be used later, but not now here.
*/