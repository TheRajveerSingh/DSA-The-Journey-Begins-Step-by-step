/*
The given problem is taken from LeetCode Q. 345
LeetCode Q.345 - Reverse Vowels of a String
Given a string s, reverse only all the vowels in the string and return it.
The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower 
and upper cases, more than once.

Example 1:
Input: s = "IceCreAm"
Output: "AceCreIm"
Explanation:
The vowels in s are ['I', 'e', 'e', 'A']. On reversing the vowels, s becomes "AceCreIm".

Example 2:
Input: s = "leetcode"
Output: "leotcede" 
*/
//..................................................................................
/*
Stratergy:
Okay, what I'm thinking is to traverse the given string(s1), 
and wherever in the string I find a vowel, I'll store them into an empty new string(s2), okay?
Now when this new string(s2) is complete with all the vowels,
I traverse s1 once again, 
and whenever I see a vowel in s1, 
I'll replace it with a letter from s2 (which I'm traversing oppositely).
okay?
*/
#include <iostream>
using namespace std;
class Solution{
    private:     //AThis is just a helper function which the main function will be using.
    bool isVowel(char ch){  //bool because we'll only be returning true or false - whether its a vowel or not
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'
        || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U';
    }
    public:
    string reverseVowels(string s){
        string vowels =" ";

        //Step 1: To Store all Vowels
        for (int i = 0; i<s.length(); i++){
            if(isVowel(s[i])){
                vowels += s[i];
            }
        }

        //Step 2: Replacing vowels from the end
        int j = vowels.length() -1; //For indexing from the last

        for (int i=0; i<s.length(); i++){
            if(isVowel(s[i])){
                s[i]=vowels[j];
                j--;                //So that index decreases
            }
        }
        return s;
    }
};