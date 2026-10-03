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
Look,
What we have to do is take '4' continuous numbers in the array, one by one,
and calculate their Avg, right?
And whichever Avg of any '4 continuous numbers' is the largest, 
we'll have to return that Avg right?
So,
Let's start by keeping 1st pointer on 0th index, and 2nd pointer on 'kth' index, right?
Why? - because the first thing we need to do is find the sum between i and k,
so we traverse between i and k-1 to get the sum. (traversing from i to k, means from i to a number one index less than k).
After getting the sum, we divide it with 'k' and tore it in a variable called 'avg'.
Now if this avg is greater what we already had in the max_avg, then it'll be the new max_avg.
Then we increase i and j so that we can take the 2nd group of continuous 4 numbers.
*/
//..............................................................................................
/*
Also, 2 things that are important to Note:
1. initiallizing 'double' max_avg:
For this, there's a concept known as " = nan("")" - Not a number
Basically till it gets a real number, it is considered an  undefined number.
I am using this because,
first I thought of initializing max_avg = 0, but zero could also be an avg of some continuous 4 numbers.
The same goes for any +ve or -ve numbers. So I had to use something by which I could initialize.
To check whether max_avg still doesn't have a number, we use .isnan().

2. While traversing through every 4 continuous elements,
its important that the last pointer 'j' reaches the nums.size(),
otherwise the very last element in the array would not be considered.
*/
//..............................................................................................
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i = 0;
        int j = k; 
        double max_avg = nan("");
        while (j<=nums.size()){
            double sum = 0;
            for (int x = i; x<j; x++){
                sum = sum + nums[x];
            }
            double avg = sum/k;
            if (isnan(max_avg) || avg>max_avg){ max_avg = avg;}
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