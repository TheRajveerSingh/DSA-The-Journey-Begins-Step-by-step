/*
This Question is taken from LeetCode Question No. 26: Remove Duplicates from Sorted Array
Question:
Given an integer array nums sorted in non-decreasing order, 
remove the duplicates in-place such that each unique element appears only once. 
The relative order of the elements should be kept the same.
Consider the number of unique elements in nums to be k​​​​​​​​​​​​​​. 
After removing duplicates, return the number of unique elements k.
The first k elements of nums should contain the unique numbers in sorted order. 
The remaining elements beyond index k - 1 can be ignored.
 
Example 1:
Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
Example 2:

Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).

Constraints:
1 <= nums.length <= 3 * 104
-100 <= nums[i] <= 100
nums is sorted in non-decreasing order.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};

int main() {
    int n;

    cout << "Enter the size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter " << n << " sorted elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;

    int k = obj.removeDuplicates(nums);

    cout << "Number of unique elements: " << k << endl;

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }

    cout << endl;

    return 0;
}
/*
Result:
Enter the size of array: 7
Enter 7 sorted elements: 1 1 3 5 6 7 7
Number of unique elements: 5
Array after removing duplicates: 1 3 5 6 7 
*/
/*
Okay, I know this is our first time doing a two-pointer sum, but don't worry.
This one is easier to understand.
'Two-pointers' is just a type of method of solving prblems.
Unlike "Arrays" or "Strings", it isn't a data structure, but mostly a method.
So like, let's first go with what are pointers?
Basically,
in c++, a pointer is any variable which is used to keep track of a position in an array/string.
So sometimes, in a given array, we might need more than one pointer, for different functions.
Might be one is used for pointing every element one by one, 
one might be used for pointing elements every 2 steps, idk, there's many probabilies.
..okay okay,
let me make it easier for you to understand..
See this question.
What has it asked?
Basically, we're given a sorted array, here, right?
Now,

*/