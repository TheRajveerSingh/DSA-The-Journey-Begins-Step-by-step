/*
The given question is from LeetCode Question 392. Is Subsequence
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
A subsequence of a string is a new string that is formed from the original string by 
deleting some (can be none) of the characters without disturbing the relative positions of the 
remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

Example 1:
Input: s = "abc", t = "ahbgdc"
Output: true
Example 2:
Input: s = "axc", t = "ahbgdc"
Output: false
*/
/*
Stratergy:
So what I have thought is that,
First I'll take an int c, where 1 will be added whenever we get an equal pair.
Now I'll take 2 pointers,
One which starts from the starting of the string s,
and one which starts from the starting of string t,
Now, for every value in string s,
if I'll find it in string t, I'll add 1 to c.
I'll then change the pointer of 'string t' to the next index, and also break the loop.
So that after 1 pair is found,
for finding the next pair,
I'll start with the second value in string s,
and to find in in string t, it'll start from that pointer to the last.
Once the size of string s == c, we know that all pairs have been found, and we can return true.
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int t_pointer = 0;
        int c = 0;
        int sz = s.size();
        for (size_t i = 0; i<s.size(); i++){
            for (size_t j = t_pointer; j<t.size(); j++){
                if (s[i]==t[j]){c+=1;
                t_pointer = j + 1;
                break;}
            }
        } if (c == sz){ return true;}
        else {return false;}
    }
};
int main(){
    Solution solver;
    string s;
    string t;
    cout<<"Enter string s: ";
    getline(cin, s);
    cout<<"Enter string t: ";
    getline(cin, t);
    if(solver.isSubsequence(s, t)){cout<<"True";} //Remember that when function return type if bool, for true(1), we do not need to compare it ==1 in the 'if' block. This is because we aren't comparing it with an interger, but with a 'bool' which by default will return true.
    else {cout<<"False";}
}
/*
Results:
Enter string s: abc         
Enter string t: jahgdbfcv
True
Enter string s: abc
Enter string t: jahcgb
False
Enter string s: abc
Enter string t: cba
False
*/