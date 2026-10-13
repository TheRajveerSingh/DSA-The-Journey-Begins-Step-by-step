/*Date: 13th Oct 2026
This is from LeetCode Question 41. First Missing Positive
Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.
You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.
Example 1:
Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.
Example 2:
Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.
Example 3:
Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.

Constraints:
1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
*/
//...................................................................................................................
/*
Thinking of the process:
So, The first thing I noticed is that here, '1' is the answer if its not there in the array.
If 1 is there, but '2' isn't, then '2' is the answer, and going on similarly.
So, 
there I was, with one thing in my mind: I'd start looking from '1' whether if it was there in the array or not.
If '1' was there, then I'd look for '2'. If '2' was there, then I'd look for '3', and so on..
Because the question asked me to return the 'least positive number' which wasn't in the array, right?
Okay,
So the first thing was to traverse through the array, and ignore the -ve numbers coming.
Now, for each positive number, I'd store it in a unordered_set.
Why?
Because after the whole array is traversed, 
we'd look into this unordered_set to find the least positive number starting from '1' - which isn't in it.
Whatever number from '1' to a particular 'max' isn't in this unordered_set, that means that that'll be the least positive number
which wasn't in the array, right?
Now, what should be this max?
first I thought it should be the max element in the array we traversed. So that between '1' and the 'maximum number',
if something isn't found in the unordered_set - that'll be the answer.
So I initialized max = INT_MIN;
however, 2 conditions were there too:
1. If all numbers from 1 to that max were already there in the array, then the answer should be max +1;
2. If the array contained only -ve numbers, we should return '1'. So if I initialized max = 0, then max+1 can be returned.
*/
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int max = 0;
        unordered_set<int> seen;
        for (size_t i = 0; i<nums.size(); i++){
            seen.insert(nums[i]);
            if (nums[i]>0){
                if(nums[i]>max){max = nums[i];}
                }
        }
        for(int j=1; j<=max; j++){
            if(seen.find(j) == seen.end()){
                return j;
            }
        }
    return max+1;
    }
};
int main(){
    Solution solver;
    cout<<"Enter the size of the array: ";
    int s;
    cin>>s;
    vector<int> nums;
    cout<<"Enter the values in the vector: ";
    int x;
    for (int k=0; k<s; k++){
        cin>>x;
        nums.push_back(x);
    }
    cout<<solver.firstMissingPositive(nums);
    return 0;
}
/*
Results:
Enter the size of the array: 3
Enter the values in the vector: 1 2 0
3
Enter the size of the array: 1
Enter the values in the vector: 1
2
Enter the size of the array: 4
Enter the values in the vector: 3 4 -1 1
2
Enter the size of the array: 5
Enter the values in the vector: 7 8 9 11 12
1
Enter the size of the array: 9
Enter the values in the vector: 1 2 3 4 5 6 7 8 9
10
*/
//Note: Although this program worked fine, and also gives Time Complexity O(n) which is good.
//However, the Space Complexity should be: O(1) Auxiliary Space Complexity. We'll try solving this problem again in the future.