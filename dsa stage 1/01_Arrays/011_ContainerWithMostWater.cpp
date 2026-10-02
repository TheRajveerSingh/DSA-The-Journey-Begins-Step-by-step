/*This question is from LeetCode Question 11. Container With Most Water
You are given an integer array height of length n. There are n vertical lines 
drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.
Notice that you may not slant the container.

Example 1:
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
Example 2:
Input: height = [1,1]
Output: 1*/

/*Note:
Now this is originally a two-pointer problem,
but since this approach came into my mind first, I'm going to note this approach down too.*/

/*Stratergy:
Look, we need to find the largest volume of water between any two heights, right?
So what I think we should do is,
in the array, we should take 1 height 'i' at a time, and then compare it with other heights 'j',
and calculate the volume of water which can be between them.
For Ex: for an array [3,4,2,9,7],
volumes of water between heights could be: (3,4), (3,2), (3,9), (3,7), (4,2), (4,9), (4,7), (2,9), (2,7), (9.7).
So for every combination of i and j, when we've calculated the volume of water between them, 
we can simply return the largest volume we've got, right?
Now, 
the most important thing is how we calculate the volume of water between them,
we just can't multiple the height * distance between them. 
Instead, we should calculate the least height between the two heights(between i and j), and the distance between them.
*/
#include <iostream>
#include <vector>
#include <algorithm> //to calculate the maximum value in an array
using namespace std;
class Solution{
    public:
    int maxArea (vector<int>& height){
        vector<int>arrnew;
        for (int i = 0; i<height.size(); i++){
            for(int j = i+1; j<height.size(); j++){
                if(height[i]<height[j]){ arrnew.push_back(height[i]*(j-i));}  //Shortest height between the two * Distance between them
                else {arrnew.push_back(height[j]*(j-i));}
            }
        }
    return (*max_element(arrnew.begin(), arrnew.end()));
    }
};
int main(){
    Solution solver;
    vector<int> height;
    int si;
    int x;
    cout<<"Enter the size of the array: ";
    cin>>si;
    cout<<"Enter the heights of poles in the array: ";
    for (int i = 0; i<si; i++){
        cin>>x;
        height.push_back(x);
    }
    cout<<solver.maxArea(height);
    return 0; //good practice
}
/*
Result:
Enter the size of the array: 9
Enter the heights of poles in the array: 1 8 6 2 5 4 8 3 7
49
Enter the size of the array: 2
Enter the heights of poles in the array: 1 1
1
Enter the size of the array: 5   
Enter the heights of poles in the array: 3 4 2 9 7
12
*/
/*
Revision:
To use the <algorithm> for the *max_element(arr.begin(), arr.end()); feature.
*/
//To check out the Two Pointer approach, please go to: File TP1003_ContainerWishMostWater.cpp