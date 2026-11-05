/*Date: 7th Oct 2026
The given question is inspired from LeetCode 560. Subarray Sum Equals K
Given an array of positive integers nums and an integer k, return the total number 
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
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution{
    public:
    int subarraySum(vector<int>& nums, int k){
        int n = nums.size();
        int i=0, j=0;
        int sum=0;
        int count=0;
        while(j<n){
            sum = sum + nums[j];

            while(sum>k && i<=j){
                sum = sum - nums[i];
                i++;
            }

            if(sum == k){count++;}

            j++;
        }
    return count;
    }
};
int main(){
    Solution solver;
    int s;
    cout<<"Enter the size of the vector: ";
    cin>>s;
    vector<int> nums;
    int x;
    cout<<"Enter the elements of the vector: ";
    for (int i=0; i<s; i++){
        cin>>x;
        nums.push_back(x);
    }
    cout<<"Enter the value of k: ";
    int k;
    cin>>k;
    cout<<solver.subarraySum(nums, k);
    return 0;
}
/*
Results:
Enter the size of the vector: 3
Enter the elements of the vector: 1 1 1
Enter the value of k: 2
2
Enter the size of the vector: 3
Enter the elements of the vector: 1 2 3
Enter the value of k: 3
2
Enter the size of the vector: 5 
Enter the elements of the vector: 1 2 3 2 1
Enter the value of k: 3
3
*/
/*
This is just the inspired version of LC 560, with just +ve numbers.
To check how the real problem was solved, go to file: PS001_SubarraySumEqualsK.cpp
*/