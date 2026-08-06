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
And then wherever it matches, we'll just return that, right?
*/
#include <iostream>
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

    int size;                            //Taking size of array
    cout<<"Enter size of array: ";
    cin>>size;

    vector<int>nums;                    //Defining and taking in elements in the array
    int element;
    cout<<"Enter the elements in the array: ";
    for (int i=0; i<size; i++){
        cin>>element;
        nums.push_back(element);
    }

    int target;                         //Asking for target value
    cout<<"Enter target No: ";
    cin>>target;

    vector<int> ans = solver.twoSum(nums, target);     //Creating another vector array to capture result from function

    if (!ans.empty()) {                                //Displaying the vector elements which captured the indexes from the function
        cout << "Output: [" << ans[0] << ", " << ans[1] << "]" << endl;
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
    
}
/*
Result:
Enter size of array: 4
Enter the elements in the array: 2 7 11 15
Enter target No: 18
Output: [1, 2]
*/
//........................................................................................................
/*
Okay, the program written above was my approach, but to make it optimized, we can directly return the indexes,
instead of storing them in a vector, it would be something like:
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j}; // A Direct, cleaner return
                }
            }
        }
        return {}; // Returns an empty vector if no match is found
    }
};
//........................................................................................................
/*
The above 2 methods are Brutforce methods, having a Time Complexity of O(n^2) because of using nested loops.
However, this would run slowly with larger inputs.
Hence, the best way to solve this 'Two Sum' problem is using a hash map (unordered_map) 
to track seen numbers and their indices in a single pass.
.......
Now I know we haven't started hash maps yet, but okay, let's try understanding how the code looks like with it, how to
go through it, and as it is, it'll give us a little early exposure to that concept.
Okay, first I'm going to write the hash map code, and then I'll write the explaination.
..
Please go to file H001_TwoSum.cpp under HashMap..I'll explain it there so that it area remains clean to array concepts.
*/
