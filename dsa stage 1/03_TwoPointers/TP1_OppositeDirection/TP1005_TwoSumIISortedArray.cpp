/*
The following question is taken from LeetCode 167. Two Sum II - Input Array Is Sorted
You are given a 1-indexed array of integers numbers that is already sorted in 
non-decreasing order.
Find two numbers such that they add up to a specific target number. 
Let these two numbers be numbers[index1] and numbers[index2] 
where 1 <= index1 < index2 <= numbers.length.
Return the indices of the two numbers index1 and index2 as an 
integer array [index1, index2] of length 2.
The tests are generated such that there is exactly one solution. 
You may not use the same element twice.
Your solution must use only constant extra space.
Example 1:
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].
Example 2:
Input: numbers = [2,3,4], target = 6
Output: [1,3]
Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].
Example 3:
Input: numbers = [-1,0], target = -1
Output: [1,2]
Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].
*/
//..............................................................................................
/*
Stratergy:
We'll use two pointers. One on the start of the array, and one on the end of it.
Now, if the sum of the values where the two pointers are is equal to the target, we push their indexes.
If its lesser than the target, we increase the 'left' pointer (so that we can get a higher value.)
If its greater than the target, we decrease the 'right' pointer.
Also, since this is a '1-indexed' array, when we push the  indexes, we'll add a '1' to it.
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int left = 0;
        int right = numbers.size()-1;
        while (left<right){
            if (numbers[left]+numbers[right] == target){ 
                ans.push_back(left+1); 
                ans.push_back(right+1);
                break;}
            else if (numbers[left]+numbers[right] < target){
                left++;
            }
            else{
                right--;
            }
        }
    return ans;
    }
};
int main(){
    Solution solver;
    cout<<"Enter the size of the array: ";
    int size;
    cin>>size;
    vector<int> numbers;
    int x;
    cout<<"Enter the values of the array: ";
    for (int i=0; i<size; i++){
        cin>>x;
        numbers.push_back(x);
    }
    cout<<"Enter the target: ";
    int t; //Know that I could also have simply names the parameter as 'target', but any function which is taking up the same 'data type' param, will take it. In short: If the twoSum function is taking an int-vector and an int, doesn't matter what 'name' we send from here.
    cin>>t; 
    vector<int> ans = solver.twoSum(numbers, t); //Remember, to print vector type returned answers from a function, we again have to store them into a vector to see its elements?
    for (int j = 0; j<ans.size(); j++){
        cout<<ans[j]<<" ";
    }
    return 0;
}
/*
Result:
Enter the size of the array: 4
Enter the values of the array: 2 7 11 15
Enter the target: 9
1 2 
Enter the size of the array: 3
Enter the values of the array: 2 3 4
Enter the target: 6
1 3 
Enter the size of the array: 2
Enter the values of the array: -1 0
Enter the target: -1
1 2 
*/