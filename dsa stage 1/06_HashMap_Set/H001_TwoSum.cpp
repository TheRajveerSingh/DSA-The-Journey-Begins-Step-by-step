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
Now, I've already solved this problem using arrays (file: 007_TwoSum.cpp).
However, that was a Brutforce method, having a Time Complexity of O(n^2) because of having nested loops, resulting it to run slowly with larger inputs.
Hence, the best way to solve this 'Two Sum' problem is using a hash map (unordered_map) to track seen numbers and their indices in a single pass.
...
Now I know hash map is new to us, but let's just check it out, okay? This way, we'll also get exposure to its concept, right?
Okay, this is the code for the problem using Hashmap:
*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(const vector<int>& nums, int target) {
        // HASH MAP: Stores { number : index }
        unordered_map<int, int> seen;
        
        // Performance boost: Pre-allocates memory so the map doesn't resize while running
        seen.reserve(nums.size());

        // Single pass through the array - O(N) Time Complexity
        for (int i = 0; i < static_cast<int>(nums.size()); i++) {
            int current_num = nums[i];
            int complement = target - current_num;

            // 1. LOOKUP: Check if the number we need is ALREADY in our map
            // map.find() runs in O(1) average time!
            if (seen.find(complement) != seen.end()) {
                // Found it! Return the saved index of complement and the current index
                return {seen[complement], i};
            }

            // 2. INSERT: Save current number and its index for future numbers to find
            seen[current_num] = i;
        }

        return {}; // No pair found
    }
};

int main() {
    Solution solver;

    int size;                                         //Asking size of array from user
    cout << "Enter size of array: ";
    cin >> size;

    vector<int> nums;                                //Creating the array
    nums.reserve(size);

    cout << "Enter " << size << " elements: ";       //Asking for the elements for the array
    for (int i = 0; i < size; i++) {
        int element;
        cin >> element;
        nums.push_back(element);
    }

    int target;                                      //Asking the user for the target
    cout << "Enter target: ";
    cin >> target;

    vector<int> ans = solver.twoSum(nums, target);   //Storing the returned indexes to a vector 'ans'

    if (!ans.empty()) {                              //Printing the elements in 'ans' (which stores the returned index from the function)
        cout << "Indices: [" << ans[0] << ", " << ans[1] << "]\n";
        cout << "Values: " << nums[ans[0]] << " + " << nums[ans[1]] << " = " << target << "\n";
    } else {
        cout << "No pair found.\n";
    }

    return 0;
}
/*
Result:
Enter size of array: 4
Enter 4 elements: 2 7 11 15
Enter target: 26
Indices: [2, 3]
Values: 11 + 15 = 26
*/