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
        string vowels =" ";  //Creating an empty new string to store vowels

        //Step 1: To Store all Vowels from given string
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
int main(){
    string s;
    cout<<"Enter a string: ";
    getline(cin, s);
    Solution solver;
    cout<<solver.reverseVowels(s);
}
/*
Result:
Enter a string: IceCreAm
AceCreIm
Enter a string: leetcode
leotcede
Enter a string: AEIOUaeiou      
uoieaUOIEA
*/
//......................................................
/*
Notes:
1. C++ doesn't have a function isVowel(), that's why we had to create our own function.
2. C++ doesn't have reverse indexing like(-1, -2,..) like Python. That's why we indexed using the string length - 1.
3. Though I've solved this problem using basic string concepts,, this problem is better solved using Two Pointers concept.
*/