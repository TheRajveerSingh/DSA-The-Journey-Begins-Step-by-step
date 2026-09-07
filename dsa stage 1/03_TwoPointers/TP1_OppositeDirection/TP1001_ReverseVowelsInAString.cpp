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
We have already solved this problem using basic strings concepts (S004_ReverseVowelsInAString.cpp).
Now, this time, we'll solve this problem using Two Pointers Concept.
What we'll be doing is taking two pointers:
One that goes from the starting of the string to the middle..  ------->  (Left to Right)
One that comes from the ending of the string to the middle..   <-------  (Right to Left)
Now, The first vowel from the starting and the first vowel from the ending will be swapped.
The second vowel from the starting and the second vowel from the ending will be swapped.
And so one, right?
So one pointer: int left = 0;
And the other: int right = s.length() - 1;
..Now this approach takes less Space then the approach we used using basic string concepts.
Because we aren't creating any extra string to store vowels.
So Space Complexity = O(1)
*/
//..................................................................................
#include <iostream>
using namespace std;
class Solution {
private:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' ||
               ch == 'o' || ch == 'u' ||
               ch == 'A' || ch == 'E' || ch == 'I' ||
               ch == 'O' || ch == 'U';
    }

public:
    string reverseVowels(string s){
        //creating both pointers
        int left = 0;
        int right = s.length() - 1;

        while(left<right){

            //To skip those alphabets which aren't vowels from left to right
            while(left<right && !isVowel(s[left])){
                left++;
            }

            //To skip those alphabets which aren't vowels from right to left
            while(left<right && !isVowel(s[right])){
                right--;
            }

            //To Swap the two aplabets where the pointers are right now
            //(These two alphabets are vowels)
            swap(s[left],s[right]);

            //After swapping, pointers keep going towards the middle
            left++;
            right--;
        }
        return s;
    }

};
int main(){
    Solution solver;
    string s;
    cout<<"Enter a string: ";
    getline(cin, s);
    cout<<solver.reverseVowels(s);
}
/*
Result:
Enter a string: aeiouAEIOU
UOIEAuoiea
Enter a string: XXaXXXeXXXIXOXXU    
XXUXXXOXXXIXeXXa
*/