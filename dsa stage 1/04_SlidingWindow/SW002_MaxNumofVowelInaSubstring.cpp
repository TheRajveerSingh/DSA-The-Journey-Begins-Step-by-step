/*
The following question is from LeetCode 1456. Maximum Number of Vowels in a Substring of Given Length
Given a string s and an integer k, return the maximum number of vowel letters
in any substring of s with length k.
Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

Example 1:
Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.
Example 2:
Input: s = "aeiou", k = 2
Output: 2
Explanation: Any substring of length 2 contains 2 vowels.
Example 3:
Input: s = "leetcode", k = 3
Output: 2
Explanation: "lee", "eet" and "ode" contain 2 vowels.
*/
//............................................................................
/*
Stratergy:
First we'll calculate the max_num of vowels in the first group.
If that max_num == k, we can immidiately return the max_num, because there isn't a need to find another group,
because the max_num can be of max k vowels.
Okay, now, suppose that doesn't happen (we don't get the max_num == k).
So now we slide through the elements like a window.
Let's take a value 'count' equal to max_num of the first group.
Now, as we slide through the second group,
if the char being dropped was a vowel, we -1 count. Why? Because 'consonants' were never added, and we need
to find the number of vowels in this current group, right? 
So why will we be keeping the count for that vowel which is leaving the group?
And if the element joining the group is a vowel, we add 1 to the count, right?
Now, we compare the value of 'count' with the max_num.
If its greater than it, it replaces it.
Now, during this process of sliding window,
if we ever find max_num ==k, we can directly return that, right? Because then that's the max count we can find.
If we find it, there won't be any reason to find a higher count.
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution{
    public:
    int maxVowels(string s, int k){
        int i = 0;
        int j = k;
        int max_num = 0;
        //For the first window
        for (int x=i; x<j; x++){
            if (s[x] == 'a' || s[x] == 'e' || s[x] == 'i' || s[x] == 'o' || s[x] == 'u'){
                max_num += 1;
            }
        if (max_num == k){ return max_num; break;} //Obv this break is not needed, because after 'return', nothing is read. I've just put it for concept of break after a condition is met.
        }
        int count = max_num;
        //sliding the window
        while(j<s.size()){
            //removing count of vowel being removed
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                count--;
            }
            //Adding count of vowel being added
            if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u'){
                count++;
            }
            if (count>max_num){max_num = count;}
            if (max_num == k){ return max_num;}
            i++;
            j++;
        }
    return max_num;
    }
};
int main(){
    Solution solver;
    string s;
    cout<<"Enter a string: ";
    getline(cin, s);
    int k;
    cout<<"Enter k's value: ";
    cin>>k;
    cout<<solver.maxVowels(s, k);
    return 0;
}
/*
Result:
Enter a string: abciiidef            
Enter k's value: 3
3
Enter a string: aeiou
Enter k's value: 2
2
Enter a string: leetcode
Enter k's value: 3
2
Enter a string: aeiou
Enter k's value: 5
5
Enter a string: aaakk
Enter k's value: 4
3
*/