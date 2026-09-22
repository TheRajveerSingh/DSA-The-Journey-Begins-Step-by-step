/*
This question is taken from LeetCode 334. Increasing Triplet Subsequence
Given an integer array nums, return true if there exists a triple of indices (i, j, k)
such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, 
return false.
Example 1:
Input: nums = [1,2,3,4,5]
Output: true
Explanation: Any triplet where i < j < k is valid.
Example 2:
Input: nums = [5,4,3,2,1]
Output: false
Explanation: No triplet exists.
Example 3:
Input: nums = [2,1,5,0,4,6]
Output: true
Explanation: One of the valid triplet is (1, 4, 5), because nums[1] == 1 < nums[4] == 4 < nums[5] == 6.
*/
//..................................................................................................................
/*
This time we'd try solving in O(n) time complexity. (File: 010_IncreasingTripletSequence.cpp using O(n^2).)
Stratergy 1:
Suppose we take: [2, 1, 5, 0, 4, 6] 
Now, here's how we do it stepwise: 
Step 1: 
1st Array : [2, 
Step 2: Since 1<2 
1st Array : [2, 
2nd Array: [1, 
Step 3: 
1st Array : [2, 5, 
2nd Array: [1, 5, 
Step 4: 
1st Array : [2, 5, 
2nd Array: [1, 5, 
3rd Array: [0, 
Step 5: 
1st Array : [2, 5, 
2nd Array: [1, 5, 
3rd Array: [0, 4, 
Step 6: 
1st Array : [2, 5, 
2nd Array: [1, 5, 
3rd Array: [0, 4, 6 -> Return True as soon as an array size is == 3.
...However there were problems such as:
1. This approach would require tracking all possible sequences, which could lead to exponential complexity.
2. We can't dynamically create vectors based on conditions in C++.
...............................................................................................................
Stratergy 2:
So we'd take two variables: smallest (first) and second smallest(second).
To find the the 2 smallest and second smallest numbers in the array together, 'second' being found after the 'first'.
If a number is found after this, that is larger than first and second, will mean that there exists a triplet.
And Hence true can be returned.
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution{
    public:
    bool increasingTriplet(vector<int>& nums){
        
    }
};
int main(){
    Solution solver;
    int s;
    int x;
    vector<int> nums;
    cout<<"Enter the size of the array: ";
    cin>>s;
    cout<<"Enter the elements in the array: ";
    for(int i=0; i<s; i++){
        cin>>x;
        nums.push_back(x);
    }
    if (solver.increasingTriplet(nums)){cout<<"True";}  //We don't need to compare bool to anything.
    else {cout<<"False";}
}