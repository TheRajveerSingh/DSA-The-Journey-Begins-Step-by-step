#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPrime(int p) { 
        vector<int> fc;

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
        unsigned long long fact = 1; //because int can overflow quickly

        for (int i = 1; i <= t; i++)
            fact *= i;

        cout << "Factorial of " << t << " = " << fact << endl;
       // Here, earlier I had written 'return 1;' but now, I've removed it as function is now 'void', and actually we don't need to return anything.
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