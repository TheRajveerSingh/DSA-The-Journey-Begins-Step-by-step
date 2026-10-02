/*
This question is taken from LeetCode Question 1679. Max Number of K-Sum Pairs
You are given an integer array nums and an integer k.
In one operation, you can pick two numbers from the array whose sum equals k and remove them from the array.
Return the maximum number of operations you can perform on the array.

Example 1:
Input: nums = [1,2,3,4], k = 5
Output: 2
Explanation: Starting with nums = [1,2,3,4]:
- Remove numbers 1 and 4, then nums = [2,3]
- Remove numbers 2 and 3, then nums = []
There are no more pairs that sum up to 5, hence a total of 2 operations.

Example 2:
Input: nums = [3,1,3,4,3], k = 6
Output: 1
Explanation: Starting with nums = [3,1,3,4,3]:
- Remove the first two 3's, then nums = [1,4,3]
There are no more pairs that sum up to 6, hence a total of 1 operation.
*/
/*
Stratergy:
We first sort the given array.
Now we keep one pointer at the left, and one at the right.
Now, if the sum of them == k, good,
If its less, we increase the value of i (i++) - because something larger has to be added right? and that larger thing would be after i.
Similarly, if its more than k, we decrease the value of j (j--).
Whenever we find a pair whose sum equals to k, we add 1 to a variable 'c', which helps counting.
*/
#include <iostream>
#include <vector>
#include <algorithm> //To use: sort
using namespace std;
class Solution{
    public:
    int maxOperations(vector<int>& nums, int k){
        sort(nums.begin(), nums.end());
        int count = 0;
        int i = 0; //left side pointer
        int j = nums.size() - 1; //right side pointer
        while (i<j){
            if (nums[i]+nums[j] == k) { count++; i++; j--;}
            else if (nums[i]+nums[j] < k) {i++;}
            else {j--;}
        }
    return count;
    }
};
int main(){
    Solution solver;
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;
    vector<int> nums;
    int x;
    cout<<"Enter the elements in the array: ";
    for (int i = 0; i<size; i++){
        cin>>x;
        nums.push_back(x);
    }
    int k;
    cout<<"Enter the target value k: ";
    cin>>k;
    cout<<solver.maxOperations(nums, k);
}
/*
Result:
Enter the size of the array: 5
Enter the elements in the array: 3 1 3 4 3
Enter the target value k: 6
1
Enter the size of the array: 7
Enter the elements in the array: 3 5 2 4 6 1
2
Enter the size of the array: 7
Enter the elements in the array: 3 5 2 4 6 1 7
Enter the target value k: 7
3
*/