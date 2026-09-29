/*
This question has been taken from leetCode Question283. Move Zeroes
Given an integer array nums, move all 0's to the end of it while maintaining the 
relative order of the non-zero elements.
Note that you must do this in-place without making a copy of the array.

Example 1:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:
Input: nums = [0]
Output: [0]
*/
/*
Stratergy:
We first keep a pointer on the first element. This pointer will help us writing the new element later after swapping.
Now, we traverse through the array,
And whenever we find an element which is not equal to zero,
we swap it with the element where the pointer is currently (which is the first zero in the array).
[Note: Before the first zero of the array, every element stays wherever they are, because
they just swap with themselves.]
After swapping, we increment that pointer.
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
      void moveZeroes(vector<int>& nums){ //Remember, function type 'void' when we don't need to actually return anything?
        int insertPointer = 0;
        for(int i=0; i<nums.size(); i++){
            if (nums[i]!=0){
                swap(nums[insertPointer], nums[i]);
                insertPointer++;
            }
        }
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
    for (int j = 0; j<size; j++){
        cin>>x;
        nums.push_back(x);
    }
    solver.moveZeroes(nums);
    //Look, previously in many programs, when we needed to print a vector returned by a function, 
    //we had to store the returned answer in another vector, and then print its element, right?
    //But here, since the 'return' type is void, and most importantly - because a new "vector" isn't 
    //being returned, infact the original "vector" is only being edited, 
    //so we do not need another vector to store. We can directly print the elements of the same original vector.
    for (int t : nums){ 
        cout<<t<<" ";
    }
}
/*
Result:
Enter the size of the vector: 5
Enter the elements of the vector: 0 1 0 3 12
1 3 12 0 0 
Enter the size of the vector: 9
Enter the elements of the vector: 1 1 2 7 0 0 0 3 2
1 1 2 7 3 2 0 0 0 
*/