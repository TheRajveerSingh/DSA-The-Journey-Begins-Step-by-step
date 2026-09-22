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
//...............................................................................................
/*
Stratergy 1:
First I thought of solving this using two pointers.. (Because maybe I learnt two pointers lately)
Basically, take the given array,
then keep a left pointer to find the minimum element in the array.
then from that 'left pointer' to the last, finding the maximum element in that array, and putting it as the right pointer.
Now between those 'left pointer' and 'right pointer', which contain the minimum and maximum element from that array,
I would traverse through the elements between them,
and if I find any number between them which is greater than the left pointer, and smaller than the right pointer,
I'd return true. However, this stratergy would fail, in array examples such as: 
[2, 1, 7, 5, 6]. Because then After taking '1' in the left pointer, it would have taken '7' as the right pointer.
So triplets such as: (1,5,6) and (2,5,6) woul have also shown 'False'
....................................................................................................
Stratergy 2:
Now, 
what I thought of is traversing through the array,
and for every element in the array,
I would traverse through the elements on its left to find the very first smallest element than it.
Similarly, I would traverse through the elements on its right to find the very first element higher than it.
Once that's done, I can return 'True'.
However, this approach would be o(n^2) time complexity, because I'm using a loop inside a loop.
(I've learnt that o(n^2) time complexity arrives when we run a loop in a loop - nested loop.
However, we are allowed to run multiple individual loops in the program with no nested loops, it'll still be o(n).)
Anyways, let's do it,
Algorithm:
Taking a number 'c' = 0,
-> If I find a number lesser in the left side, adding '1'.
-> If I find a number greater in the right side, adding '1'.
-> ic c==2, returning true. Otherwise false.
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution{
    public:
    bool increasingTriplet(vector<int>& nums){
        for (int i=0; i<nums.size(); i++){ //for every element in the given array
            int c = 0;  //will be used to calculate later
            for (int left=0; left<i; left++){  //traversing through the left elements of 'i'
                if (nums[left]<nums[i]){c += 1; break;} //'break' because finding the first smallest element will do.
            }
            for (int right=i+1; right<nums.size(); right++){ //for right element
                if (nums[right]>nums[i]){c +=1; break;}
            }
            if (c==2){return 1;} //Return true
        }
        return 0; //Otherwise false
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
/*
Results:
Enter the size of the array: 5
Enter the elements in the array: 1 2 3 4 5 
True
Enter the size of the array: 5
Enter the elements in the array: 5 4 3 2 1
False
Enter the size of the array: 6
Enter the elements in the array: 2 1 5 0 4 6 
True
Enter the size of the array: 5   
Enter the elements in the array: 2 1 7 5 6
True
*/