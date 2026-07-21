/*This question is part of Leetzcode 75:
1071. Greatest Common Divisor of Strings
Basically, 
When two strings str1 and str2 are given, 
we have to return the largest string such that it divides both str1 and str2.
For now, these strings should only be English UpperCase Letters.
............................
Stratergy:
So if there should be a GCD for 2 strings, 
it should be such that it divided both strings in whole, leaving no remainder, right?
That means,
The string gcd should itself be there in both strings given, either 1 copy or more, but not half or extra, right?
So, first, to confirm that, what we can do is: if str1 + str2 == str2 + str1
By this, we confirm that there is a common gcd that divides them fully,
If its not, that means no gcd exists for both the given strings.
..........
Now, in c++,
gcd(a, b) is a built-in function from the <numeric> header that calculates 
the largest integer that divides both a and b cleanly with zero remainder.
so
*/
#include <iostream>
#include <string>
#include <numeric> // Required for gcd
using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // Check if a valid common divisor string exists
        if (str1 + str2 != str2 + str1) {
            return "";
        }
        
        // Find the GCD of the lengths of the two strings
        int gcd_length = gcd(str1.length(), str2.length());
        
        // Return the prefix of that length
        return str1.substr(0, gcd_length);
    }
};

int main() {
    Solution solver;

    // Test Case 1
    string str1 = "ABCABC";
    string str2 = "ABC";
    cout << "Test 1 Output: " << solver.gcdOfStrings(str1, str2) << " (Expected: ABC)\n";

    // Test Case 2
    string str3 = "ABABAB";
    string str4 = "ABAB";
    cout << "Test 2 Output: " << solver.gcdOfStrings(str3, str4) << " (Expected: AB)\n";

    // Test Case 3
    string str5 = "LEET";
    string str6 = "CODE";
    cout << "Test 3 Output: \"" << solver.gcdOfStrings(str5, str6) << "\" (Expected: \"\")\n";

    return 0;
}
