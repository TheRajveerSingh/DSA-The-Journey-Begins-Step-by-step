/*
The given question is from LeetCode Question. 643. Maximum Average Subarray I
You are given an integer array nums consisting of n elements, and an integer k.
Find a contiguous subarray whose length is equal to k that has the maximum average value 
and return this value. Any answer with a calculation error less than 10-5 will be accepted.
Example 1:
Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
Example 2:
Input: nums = [5], k = 1
Output: 5.00000
*/
//..............................................................................................
/*
Stratergy:
Even though I have solved this question with the help of Arrays in File "012_MaxAvgSubarray1.cpp",
This is a sliding window problem.
So, here, what we'll do is,
We'll take the sum of the first set of 4 elements, and calculate their avg, okay?
Now, for the rest of the continuous groups,
we'll apply a 'sliding window'..basically,
for the sum of the next set of 4 elements, we drop the very first element, and take the next element.
Ex: First group: 1, 12, -5, -6
second group, 12, -5, -6, 50 (we dropped '1' and added '50').
And calculate the avg - if its larger than the value already as the 'max_avg', we just change it.
*/
//..............................................................................................
#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
     double findMaxAverage(vector<int>& nums, int k) {
        int i = 0;
        int j = k;
        double sum = 0;

        //Calculating the first window
        for (int x=i; x<j; x++){
            sum = sum + nums[x];
        }
        double max_avg = sum/k;

        //sliding the window
        while (j<nums.size()){
            sum = sum - nums[i] + nums[j];
            double avg = sum/k;
            if (avg>max_avg){ max_avg = avg;}
            i++;
            j++;
        }
    return max_avg;
    }
};
int main(){
    Solution solver;
    vector<int> nums;
    int size;
    cout<<"Enter the size of the vector: ";
    cin>>size;
    int x;
    cout<<"Enter the elements of the vector: ";
    for (int i = 0; i<size; i++){
        cin>>x;
        nums.push_back(x);
    }
    int k;
    cout<<"Enter the value of k: ";
    cin>>k;
    cout<<solver.findMaxAverage(nums, k);
    return 0;
}
/*
Result:
Enter the size of the vector: 6                               
Enter the elements of the vector: 1 12 -5 -6 50 3
Enter the value of k: 4
12.75
Enter the size of the vector: 1
Enter the elements of the vector: 5
Enter the value of k: 1
5
*/