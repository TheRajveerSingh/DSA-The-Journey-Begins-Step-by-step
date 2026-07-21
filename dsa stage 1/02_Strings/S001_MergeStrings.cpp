/*This question was part of LeetCode 75:
1768. Merge Strings Alternately
The goal of this program is to merge strings alternatively.
*/
#include <iostream>
#include <string> 
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result = ""; //We declare a string result to capture letters from both strings
        int i = 0; 
        //Let's dry run with word 'rn' and 'ttt'.
        while (i < word1.length() || i < word2.length()) { // (0<2 || 0<3), so this will keep going till i reaches the last index of the longest string
            if (i < word1.length()) {                      //0<2
                result += word1[i];                        //result = r
            }
            if (i < word2.length()) {                      //0<3
                result += word2[i];                        //result = rt ; this will eventually be the last result
            }
            i++;                                           //i=1
        }
        
        return result;
    }
};

int main() {
    Solution solver;
    string word1, word2;
    
    cout << "Enter string 1: ";
    cin >> word1;
    cout << "Enter string 2: ";
    cin >> word2;

    cout << "Merged result: " << solver.mergeAlternately(word1, word2) << endl; 
    
    return 0;
}
/*
Result:
Enter string 1: abcd                                                                                     
Enter string 2: pqrs
Merged result: apbqcrds
Enter string 1: rajveersingh      
Enter string 2: nishant
Merged result: rnaijsvheaenrtsingh
Enter string 1: kg
Enter string 2: ttttttt
Merged result: ktgtttttt
*/