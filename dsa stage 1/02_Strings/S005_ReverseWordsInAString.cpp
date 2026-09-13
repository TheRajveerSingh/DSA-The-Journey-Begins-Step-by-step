/*
This Question is taken from LeetCode Q.151.
151. Reverse Words in a String 
Given an input string s, reverse the order of the words. 
A word is defined as a sequence of non-space characters. 
The words in s will be separated by at least one space. 
Return a string of the words in reverse order concatenated by a single space. 
Note that s may contain leading or trailing spaces or multiple spaces between two words. 
The returned string should only have a single space separating the words. Do not include any extra spaces. 

Example 1: 
Input: s = "the sky is blue" 
Output: "blue is sky the" 
Example 2: 
Input: s = " hello world " 
Output: "world hello" 
Explanation: Your reversed string should not contain leading or trailing spaces. 
Example 3: Input: s = "a good example" 
Output: "example good a" 
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
*/
//.............................................................................................................
/*
Stratergy:
To read the given string.
Then to seperate each word from the string (by using stringstream).
Storing each word in a vector array.
Lastly printing the words in that array backwards.
*/
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
class Solution{
    public:
    string reverseWords(string s){
        stringstream ss(s); //To capture individual words from string s
        string word;        //individual 'word' from ss to be pushed into a vector array
        vector<string> words;  //To push 'word' from ss to a vector array 'words'
        string ans;         //Used to store words while traversing the vector from backwards

        //Extracting words - For every word being given out by ss for string s
        while(ss >> word){
            words.push_back(word);
        }

        //traversing and storing words in 'ans' from the back of the array
        for (int i = words.size() - 1; i>=0; i--){
            ans += words[i];

            //So that after every word added, a space can also be there
            if (i != 0) {
                ans += " ";
            }
        }
        return ans;
    }
};
int main(){
    Solution solver;
    string s;
    cout<<"Enter a string: ";
    getline(cin, s);
    cout<<solver.reverseWords(s);
}
/*
Result:
Enter a string: The Sky is Blue
Blue is Sky The
Enter a string: Why   is    there so  confusing           spaces  randomly 
randomly spaces confusing so there is Why
*/