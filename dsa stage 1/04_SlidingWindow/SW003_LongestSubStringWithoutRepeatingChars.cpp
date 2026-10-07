/*Date: 07/10/2026
This question is from LeetCode 3. Longest Substring Without Repeating Characters
Given a string s, find the length of the longest substring without duplicate characters.

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/
//..................................................................................................
/*
Stratergy:
So my stratergy was simple. I would have two indexes- i and j, and I would keep pushing j forward.
and if it was not already contained in the 'unordered set', I would add it to it.
Things initialized: int i = 0, int j = 0, max_count = 0, count = o, unordered_set<char> seen;
So if the element at j was not in the unordered_set , I would add it there, count++, and also j++.
If the count> max_count, then max_count = count.
However, if a character at 'j' came which was already seen, then I would clear the 
whole unordered_set till j(not including j), and now point i and j to that place.
................................................
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int j = 0;
        unordered_set<char> seen;
        int max_count = 0;
        int count = 0;
        while(j<s.size()){
            if (seen.find(s[j]) == seen.end()){
                seen.insert(s[j]);
                count +=1;
                if (count>max_count){max_count = count;}
                j++;
            }
            else {
               seen.erase(s[i]);
               i++;
               count--;
            }
        }
        return max_count;
    }
};
.................................................
Now, this approach actually worked on leetcode for the three above cases,
and also in many cases such as "abcabcdefab".
However, in some cases, like "541R19T5", the answer won't be: 19T5, but would be R19T5.
So I understood that I had to continue from that 'element' just after the 1st occurence 
of the recently seen duplicate(at s[j]). So here's the correct code:
*/
#include <iostream>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int j = 0;
        unordered_set<char> seen;
        int max_count = 0;
        int count = 0;
        while(j<s.size()){
            if (seen.find(s[j]) == seen.end()){
                seen.insert(s[j]);
                count +=1;
                if (count>max_count){max_count = count;}
                j++;
            }
            else {
               seen.erase(s[i]);
               i++;
               count--;
            }
        }
        return max_count;
    }
};
int main(){
    cout<<"Enter a string: ";
    string s;
    getline(cin, s);
    Solution solver;
    cout<<solver.lengthOfLongestSubstring(s);
    return 0;
}
/*
Result:
Enter a string: abcabcbb                                        
3
Enter a string: abcdecbeads
6
Enter a string: a
1
*/