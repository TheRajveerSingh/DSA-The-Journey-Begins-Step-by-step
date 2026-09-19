/*
This question is from LeetCode 238. Product of Array Except Self
Given an integer array nums, return an array answer such that answer[i] is equal to the 
product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation.

Example 1:
Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
*/
//................................................................................................
/*
Stratergy:
First I thought of just multipling all the elements of the array at once, and then dividing them with each element in the array.
But this stratergy fails when we have '0' in the array. Additionally, the question explicity mentions not to use the division operator.
So,
what we do is, 
that for each element in the array,
we multiply all the elements in the right side,
and then multiply all the elements in the left side,
and then multiply both of those results (left * right), and place the answer in that index's place itself, right?
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution{
    public:
    vector<int> productExceptSelf(vector<int>& nums){
        int n = nums.size();
        vector<int> answer(n);

        for (int i=0; i<n; i++){   //For each 'i' in the array nums

            //Calculating left
            int left = 1;
            for (int j=0; j<i; j++){
                left *= nums[j];
            }
            //Calculating right
            int right = 1;
            for (int j=i+1; j<n; j++){
                right *= nums[j];
            }

            answer[i] = left * right;  //placing the value in that very index location in the new array
        }
        return answer;
    }
};
int main(){
    int n, m;
    vector<int> nums;
    cout<<"Enter the size of the array: ";
    cin>>n;
    cout<<"Enter the values of the array: ";
    for (int k=0; k<n; k++){
        cin>>m;
        nums.push_back(m);
    }
    Solution solver;
    vector<int> answer = solver.productExceptSelf(nums);  //Remember that when we need to print the elements of a returned vector, we have to store it again in a vector and traverse it to print its elements.
    for(int t : answer){
        cout<<t<<" ";
    }
    return 0;
}
/*
Results:
Enter the size of the array: 5
Enter the values of the array: 1 2 3 4 5
120 60 40 30 24 
Enter the size of the array: 4
Enter the values of the array: 1 2 3 4
24 12 8 6 
Enter the size of the array: 5
Enter the values of the array: -1 1 0 -3 3
0 0 9 0 0 
*/