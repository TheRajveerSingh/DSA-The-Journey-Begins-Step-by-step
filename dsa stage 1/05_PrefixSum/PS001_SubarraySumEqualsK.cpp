/*Date: 7th Oct 2026
THe given question is from LeetCode 560. Subarray Sum Equals K
Given an array of integers nums and an integer k, return the total number 
of subarrays whose sum equals to k.
A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:
Input: nums = [1,1,1], k = 2
Output: 2
Example 2:
Input: nums = [1,2,3], k = 3
Output: 2
*/
//...........................................................................................
/*
Stratergy:
This is how I'm thinking to solve this problem.
Let's take an exaple of: 1,2,3,2,1
Now:
there will be two pointers: i and j, pointing towards any two elements. i being lesser than j always.
Now, what I'm thinking about is:
-> Whenever we see an "equal to" or "lesser than k" -> We move forward with j.
-> Whenever we see a "greater than k" -> we move i forward (basically remove the current element at i).
So like, for the given example,
i and j are at 1 -> 1<3 -> doing j++
i is at 1, j is at 2 -> 1+2=3 -> Count++ -> doing j++
i is at 1, j is at 3 -> 1+2+3>3 -> doing i++
i is at 2, j is at 3 -> 2+3>3 -> doing i++
i and j are at 3 -> 3=3 -> Count++ > doing j++
i is at 3, j is at 2-> 3+2>3 -> doing i++
i and j are at 2 -> 2<3 -> doing j++
i is at 2, j is at 1 -> 2+1=3 -> Count++ -> j<nums.size() -> loop ends
At the end we return Count.
.........
However, one big issue with this approach is that, it won't work with arrays with negative numbers.
Check File: SW004_PositiveSubarraySumEqualsK.cpp"
*/
//.......................................................................................
//.......................................................................................
/*
Okay, so after researching, I got to know that this is a Prefix Sum + HashMap Problem.
Now, I know we're new to prefix Sum Concept, but anyhow, let's see how this goes.
*/

