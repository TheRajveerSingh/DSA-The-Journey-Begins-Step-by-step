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
/*
Stratergy:
I already performed this problem in File '011_ContainerWithMostWater.cpp' where I used Array and loop concept.
However, the time complexity for that approach was o(n^2).
Hence this is the two pointer approach.

Now, what we do, is take two pointers, okay?
We keep one at the very left height (starting from index 0)
and we keep one at the very right height (starting from index height.size() - 1)
Now, we calculate the Volume between these two heights, okay?
[Note:
To calculate the volume, we simply can't multiply the heights * width.
Instead, we have to multiply the minumum height between them and the distance between them(right - left).]
Now,
after getting the Volume between them, 
we check between these two heights, which one is the smallest.
Why? Because that's the height stopping from having a greater volume, right?
So we move that pointer inward, okay?
So between height[left] and height[right], if value of 'left' is smaller, we move inward --> left++;
If the value of 'right' is smaller, we move inward <--- right--;
We calculate the volume between the height we kept and the new height we got. If the volume is greater than that we had,
we now store the new Volume.
In the last, whatever volume is get, is the greatest, right?
Let's implement that now
*/
# include <iostream>
# include <vector>
# include <algorithm>  //This will be used for using features: max and min
using namespace std;
class Solution{
    public:
    int maxArea(vector<int>& height){
        int max_Volume = 0;
        int left = 0;
        int right = height.size() - 1;
        while (left<right){
            int width = right - left;
            int heightused = min(height[left], height[right]);
            max_Volume = max(max_Volume, width * heightused);

            if(height[right]<height[left]){ right --;}
            else {left ++;}
        }
        return max_Volume;
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
*/