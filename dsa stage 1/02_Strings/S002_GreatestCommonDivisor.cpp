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
