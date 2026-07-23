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

        unordered_map<int, int> seen; // HASH MAP: Stores { number : index }
        
        seen.reserve(nums.size()); // Performance boost: Pre-allocates memory so the map doesn't resize while running

        // Using size_t matches nums.size() perfectly, avoiding signed/unsigned warnings
        for (size_t i = 0; i < nums.size(); i++) { // Single pass through the array - O(N) Time Complexity
            int current_num = nums[i];
            int complement = target - current_num;

            // 1. LOOKUP: Check if the number we need is ALREADY in our map
            // map.find() runs in O(1) average time!
            if (seen.find(complement) != seen.end()) {
                // Found it! Return the saved index of complement and the current index
                return {seen[complement], static_cast<int>(i)};
            }

            // 2. INSERT: Save current number and its index for future numbers to find
            seen[current_num] = static_cast<int>(i);
        }

        return {}; // Return empty if no pair found
    }
};

int main() {
    Solution solver;

    size_t size;                                     // Asking size of array from user (using size_t)
    cout << "Enter size of array: ";
    cin >> size;

    vector<int> nums;                                // Creating the array
    nums.reserve(size);                              // We already reserve the size of the array, for time saving optimization.

    cout << "Enter " << size << " elements: ";       // Asking for the elements for the array
    for (size_t i = 0; i < size; i++) {
        int element;
        cin >> element;
        nums.push_back(element);
    }

    int target;                                      // Asking the user for the target
    cout << "Enter target: ";
    cin >> target;

    vector<int> ans = solver.twoSum(nums, target);   // Storing the returned indexes to a vector 'ans'

    if (!ans.empty()) {                              // Printing the elements in 'ans' (which stores the returned index from the function)
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
//..................................................................................................................
//..................................................................................................................
/*
Here's the comparision between this hashmap approach, and the array approach we used earlier.

1. The Array Approach (Brute Force):
Think of our old solution like looking for two people in a crowded room whose heights add up to 10 feet.
-> We pick person 1 (nums[i]). 
-> We walk through everyone else in the room (nums[j]) to check: "Does your height + person 1's height equal 10?"
-> If not, we pick person 2, and walk through the room all over again.
-> Why it's slow: With 10,000 numbers, we end up checking pairs up to 100,000,000 times. That is O(n^2) time.

2. The Hash Map Approach (The Notebook)
Instead of searching through the room over and over, imagine carrying a notebook (unordered_map).
As we walk past each person once: 
-> We ask: "If I am holding number 7, and the target is 10, I need a 3. Is '3' already written in my notebook?
-> If YES: We look at the page for '3', grab its position, and we're done.
-> If NO: We write down our own number and position in the notebook (7 -> index 0) so future people can find us, and we move to the next person.
Because opening a notebook to a specific page takes instantly O(1) time, we only make one single pass through the array. 
This drops the time down to O(n) time.
*/
//..................................................................................................................
//..................................................................................................................
/*
Explaination:
So consider a Hash-Map basically like a Dictionary in Python.
Now, here to create a hashmap, we used: unordered_map<int, int> hashmap_name; where the first value is the key, and second is the value.
Now, in the int main():
Its basically the same thing, taking in the array, the target, and then displaying the result.
Something new: the nums.reserve(size); 
This helps pre-allocate memory to the vector, basically reducing the effort of wasting time to create more memory when the vector thinks it needs to.
If we see in the function part too, we see: seen.reserve(nums.size());
where basically, here too, we are pre-allocating size of memory to the hashmap for efficiency.
..............................
Now, coming to the function,
First we created a hashmap, right? with: unordered_map<int, int> hashmap_name;

*/