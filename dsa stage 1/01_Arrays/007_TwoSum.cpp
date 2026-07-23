/*
This question is from LeetCode Q1. Two Sum
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.
Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]
*/
//............................................................................................................
/*
Stratergy:
Okay, so how would we do it in real life?
let's take an example:
nums=[2,7,11,15], and target=18, okay? 
So, we'd do 2+7 = 9; 2+11 = 13; 2+15 = 17; 
Now, 7+11 = 18 (found it)
..so basically, we take 1 number from the array, and try adding it with every other number in the array, right?
So that means, for an array [a,b,c,d,e] and target = t, our approach stepwise would be like:
a+b, a+c, a+d, a+e, b+c, b+d, b+e, c+d, c+e, d+e, right?
...
So with this stratergy, let's traverse though the array and take 1 number at a time, right?
and then with that number(let's call it num1), we again traverse through the array (excluding that same number), 
and try with the other numbers after that num1's location, right?
And then whereever it matches, we'll just return that, right?
*/
#include <iosteam>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>result;
        for (int i = 0; i<nums.size(); i++){
            for (int j = i +1; j<nums.size(); j++){ //Starting j at i + 1 to never reuse indices or duplicate checks
                if (nums[i]+nums[j]==target){
                    result.push_back(i); 
                    result.push_back(j);
                    return result;}
            }
        }
        return result;
    }
};
int main(){
    Solution solver;

    int size;
    cout<<"Enter size of array: ";
    cin>>size;

    vector<int>nums[size];
    int j;
    for (int i=0; i<nums.size(); i++)[
        cin>>j;
        nums.push_back(j);
    ]

    int target;
    cout<<"Enter target No: ";
    cin>>target;

    cout<<solver.twoSum(nums, target);
    
}