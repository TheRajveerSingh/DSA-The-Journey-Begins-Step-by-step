#include <iostream>
#include <string> 

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result = "";
        int i = 0;
        
        while (i < word1.length() || i < word2.length()) {
            if (i < word1.length()) {
                result += word1[i];
            }
            if (i < word2.length()) {
                result += word2[i];
            }
            i++;
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
*/