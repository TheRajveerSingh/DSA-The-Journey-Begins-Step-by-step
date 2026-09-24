/*
This question is from LeetCode 443. String Compression
Given an array of characters chars, compress it using the following algorithm:
Begin with an empty string s. For each group of consecutive repeating characters in chars:
If the group's length is 1, append the character to s.
Otherwise, append the character followed by the group's length.
The compressed string s should not be returned separately, but instead, be stored in the input character array chars. 
Note that group lengths that are 10 or longer will be split into multiple characters in chars.
After you are done modifying the input array, return the new length of the array.
You must write an algorithm that uses only constant extra space.
Note: The characters in the array beyond the returned length do not matter and should be ignored.

Example 1:
Input: chars = ["a","a","b","b","c","c","c"]
Output: 6
Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".
After modifying the input array in-place, the first 6 characters of chars should be ["a","2","b","2","c","3"].
Example 2:
Input: chars = ["a"]
Output: 1
Explanation: The only group is "a", which remains uncompressed since it is a single character.
After modifying the input array in-place, the first character of chars should be ["a"].
Example 3:
Input: chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
Output: 4
Explanation: The groups are "a" and "bbbbbbbbbbbb". This compresses to "ab12".
After modifying the input array in-place, the first 4 characters of chars should be ["a","b","1","2"].
*/
//....................................................................................................................
/*This was the algorithm I thought of first:
#include <iostream>
#include <vector>
using namespace std;
class Solution{
    public:
    int compress (vector<char>& char1){
        int output = 0;
        int pointer1 = 0;
        char1.push_back('n');
        for (int i = 1; i<char1.size(); i++){
            if (char1[i]!=char1[i-1]){
                int size1 = i - pointer1;
                if (size1 == 1){output += 1;}
                else if (100>size1>=10){output += 3;}
                else if (size1>=100){output += 4;}
                else {output += 2;}
                pointer1 = i;
            }
        }
    return output;
    }
};
Basically, with the help of two pointers, pointer1 on every starting of a group of char, 
while i on the first char of the next group. By calculating the difference between i and pointer1, I get the size of that group.
Now, after getting the size, if its only '1', I'll add only 1. Why? because that the example of [a], it'll show only '1'.
For cases above 10, it'll add '3', why? because [a,a,a,..] 12 a's would give [a12] which would be equal to adding '3'.
For other cases, of group sizes from 2 to 9, for example, [a,a,a,a] would give [a4], so we'll add '2' to the output.
However,
When I ran this on Leetcode, it expected me to show the overwritten array, ex: ['a', '1', 'b', 'b', '2'], and
my code just tried printing the output. So anyways, 
let's try implementing it in the leetcode way, but I'll try to print both the array, and the output number.
..Also, while overwriting the 'char' arrray, if the 'char' elements are larger in size than those elements overriding it,
we simply ignore the characters left at the end of the char array, as they won't matter.
*/
