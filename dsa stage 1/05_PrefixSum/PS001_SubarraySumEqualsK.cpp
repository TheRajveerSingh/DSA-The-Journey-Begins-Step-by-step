/*Date: 7th Oct 2026 - 10th Aug 2026 (Yeah understanding this took a lot of time)
THe given question is from LeetCode 560. Subarray Sum Equals K
Given an array of integers nums and an integer k, return the total number 
of subarrays whose sum equals to k.
A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:
Input: nums = [1,1,1], k = 2
Output: 2
Example 2:
Input: nums = [1,2,3], k = 3
Output: 2
*/
//...........................................................................................
/*
Stratergy:
This is how I'm thinking to solve this problem.
Let's take an exaple of: 1,2,3,2,1
Now:
there will be two pointers: i and j, pointing towards any two elements. i being lesser than j always.
Now, what I'm thinking about is:
-> Whenever we see an "equal to" or "lesser than k" -> We move forward with j.
-> Whenever we see a "greater than k" -> we move i forward (basically remove the current element at i).
So like, for the given example,
i and j are at 1 -> 1<3 -> doing j++
i is at 1, j is at 2 -> 1+2=3 -> Count++ -> doing j++
i is at 1, j is at 3 -> 1+2+3>3 -> doing i++
i is at 2, j is at 3 -> 2+3>3 -> doing i++
i and j are at 3 -> 3=3 -> Count++ > doing j++
i is at 3, j is at 2-> 3+2>3 -> doing i++
i and j are at 2 -> 2<3 -> doing j++
i is at 2, j is at 1 -> 2+1=3 -> Count++ -> j<nums.size() -> loop ends
At the end we return Count.
.........
However, one big issue with this approach is that, it won't work with arrays with negative numbers.
Check File: SW004_PositiveSubarraySumEqualsK.cpp"
*/
//.......................................................................................
//.......................................................................................
/*
Okay, so after researching, I got to know that this is a Prefix Sum + HashMap Problem.
Now, I know we're new to prefix Sum Concept, but anyhow, let's see how this goes.
So,
Prefix Sum Concept is nothing but a running sum of each index's value upto that index.
For each position, we store the sum of everything from the start upto that position.
And suppose if we want to know the sum of elements between index 3 and 8, what do we do?
We basically take the running total sum at index 8, and minus the running total till index 2.
So we get the sum of elements between index 3 and 8.
..
Now, suppose in a given array, if we want to find number of subarrays whose sum = 3.
What can we do? 
Basically, if we take the current running sum till that index (curr), and minus '3',
and if there exists a (curr - k) sum in the array - that means that'll be a valid subarray, right?
So the number of subarrays = number of times we get (curr-k) as a running sum to any index in the array, right?
..
So what we're gonna do is - first of all as we traverse through the array, we'll calculate the running sum(curr) till that index.
Everytime we find a new "curr", we add it to the hashmap, right?
And if that curr already exists, we would just update its frequency.
Now, For that specific "running sum (curr)", if we find (curr - k) "running sum" already in the array, 
then that'll imply that there exists a valid subarray, right?
If that (curr - k) is found, then we add the number of times(frequency) of that (curr - k) we found earlier to count, right?
okay, let's code now..
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution{
    public:
    int subarraySum(vector<int>& nums, int k){
        unordered_map<int, int> notebook; //A Hashmap with stores {Running Sum: No.Of Times that running sum was seen}
        notebook[0] = 1; //The running sum will start from 0 right? Because sum=0 has been seen 'once' before we even start adding the elements of the array, right?
        int curr = 0; //To calculate the running total till every index. If we find it the first time, we add it to the hadmap with frequency = 1. Otherwise if that sum was already there, we just update its frequency.
        //One thing to remember is that as the array continues, its not nesessary that the sum keeps adding up. Ex: for [3, -3, 3], the running totals may be: 0, 3, 0, 3.
        int count = 0; //No. of times we find a valid subarray -> No.of times we found (curr - k) in the hashmap.
        //because remember: Every 'curr' we add in a hashmap, also acts as a (curr - k) for some other curr ahead.
        
        for (int i = 0; i<nums.size(); i++){
            curr += nums[i]; //1. We calculate the running total

            int hunted = curr - k;  //2. We calculate what we want to find so that we know whether a valid subarray exists.

            if (notebook.find(hunted) != notebook.end()){ //If (curr - k) is found in the hashmap:
                count = count + notebook[hunted];   //3. Add the number of times we had found (curr - k) to count.
            }

            if(notebook.find(curr) != notebook.end()){
                notebook[curr]++;                   //4. If the (curr) "current running sum" was already in the hashmap, updating its frequency to 1.
            }
            else {notebook[curr] = 1;}              //5. If the (curr) "current running sum" is new, we add it to the hashmap, with frequency 1.
        }
    return count;

    }
};
int main(){
    Solution solver;
    cout<<"Enter the size of the vector: ";
    int s;
    cin>>s;
    vector<int> nums;
    cout<<"Enter the elements of the vector: ";
    int x;
    for (int j = 0; j<s; j++){
        cin>>x;
        nums.push_back(x);
    }
    int k;
    cout<<"Enter the value of k: ";
    cin>>k;
    cout<<solver.subarraySum(nums, k);
    return 0;
}
/*
Results:
Enter the size of the vector: 3
Enter the elements of the vector: 1 1 1
Enter the value of k: 2
2
Enter the size of the vector: 3
Enter the elements of the vector: 1 2 3
Enter the value of k: 3
2
Enter the size of the vector: 5
Enter the elements of the vector: 1 2 3 2 1
Enter the value of k: 3
3
Enter the size of the vector: 10
Enter the elements of the vector: 1 2 3 -3 1 1 1 4 2 -3
Enter the value of k: 3
8
*/
