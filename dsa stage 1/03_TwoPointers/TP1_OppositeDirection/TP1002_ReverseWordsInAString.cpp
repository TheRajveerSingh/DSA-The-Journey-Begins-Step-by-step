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
/*
Stratergy:
We have already solved this problem by normal string concepts (file: 'S005_ReverseWordsInAString.cpp')
-> By using the two pointer technique, we can reduce the Space complexity from O(n) to O(1).
-> This is because we don't need to create an extra vector array here this time.
Okay, so let's take an example:
"The Sky is blue     "
We're going to print this string in reverse right? So we'll start from reverse, okay? (From right to left)
Okay..here's what we do now..
From the right, first of all we have to skip spaces (if it exists) till we get to a word, right?
Basically, in this sentence, we know we've hit a word, when we reach 'e' of 'Blue' right?
Now from last character of every word, we take another pointer and that also moves toward the right unless it sees a 'space'.
Basically that'll mean that it has reached the first character of that same word, right? Here that'll be 'B' of 'Blue'.
Now, if you notice,
basically the whole word 'Blue' is between these two pointers right? So as soon as we get a word in between these two pointers,
we will print it. Then again the process continues..
Again we skip 'spaces' till we find the end character of another word, and then find the starting character of that same word,
and then print that word between those two pointers..
...
So first of all, let's have two pointers i and j, which will help locate the boundaries of every word.
*/
#include <iostream>
#include <string>
using namespace std;
class Solution{
    public:
    string reverseWords(string s){
        string ans = "";
        int i = s.size() - 1;  //pointer i starts from thr very back of the string

        while (i>=0){

            //To skip spaces:
            while (i>=0 && s[i]==' '){
                i--;
            }

            //If all words are over
            if (i<0){ break; }

            //Real Conditions for Words
            int j = i;   //So that both j and i pointers initially start from the end character of a word

            //To move pointer 'j' leftwards until we get a 'space'
            while (j>=0 && s[j]!=' '){
                j--;
            }

            //Now a 'word' is between j and i pointers, we need to add them
            if (!ans.empty()){ ans +=" ";}  //For the first time, no space would be added. But a space will be added after every word.

            ans += s.substr(j+1, i-j);  //'j' in on the 'space' right? So from j+1(the first char of the word) to its length of the word.

            i = j; //After the word is added, i and j come together in the same place again.

        }
        return ans;

    }
};
int main(){
    cout<<"Enter a String: ";
    string s;
    getline(cin, s);
    Solution classObject;
    cout<<classObject.reverseWords(s);
}
/*
Result:
Enter a String: The Sky is Blue                              
Blue is Sky The
Enter a String: Why    is there   so Random              spaces   in  this sentence  ?
? sentence this in spaces Random so there is Why
*/