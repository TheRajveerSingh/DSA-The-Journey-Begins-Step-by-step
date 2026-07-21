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
So, what we do is, if we take the length of the both the strings, 
then gcd will give the length of the resultant string, right?
....
Now, we return the substring of the length got from any one of the given strings, 
as that would basically be the answer (because after that prefix, the same gcd will repeat).
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
        
        // To find the GCD of the lengths of the two strings
        int gcd_length = gcd(str1.length(), str2.length());
        
        // This will return the prefix of that length; which would literally be the resultant (because after that prefix, the same gcd will repeat)
        return str1.substr(0, gcd_length);
    }
};

int main() {
    Solution solver;
    string str1, str2;
    cout<<"Enter String 1: ";
    cin>>str1;
    cout<<"Enter String 2: ";
    cin>>str2;
    cout << "The Greatest Common Substring which can divide both given strings is: " << solver.gcdOfStrings(str1, str2);
    return 0;
}
/*
Result:
Enter String 1: ABCABCABC                         
Enter String 2: ABC
The Greatest Common Substring which can divide both given strings is: ABC
Enter String 1: ADvADvADv
Enter String 2: ADvADvADvADvADv
The Greatest Common Substring which can divide both given strings is: ADv
*/