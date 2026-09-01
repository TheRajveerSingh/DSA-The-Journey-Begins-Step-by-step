/*
This Question is taken from LeetCode Question.605:
605. Can Place Flowers
You have a long flowerbed in which some of the plots are planted, and some are not. 
However, flowers cannot be planted in adjacent plots.
Given an integer array flowerbed containing 0's and 1's, 
where 0 means empty and 1 means not empty, and an integer n, 
return true if n new flowers can be planted in the flowerbed without violating 
the no-adjacent-flowers rule and false otherwise.

Example 1:
Input: flowerbed = [1,0,0,0,1], n = 1
Output: true
Example 2:
Input: flowerbed = [1,0,0,0,1], n = 2
Output: false
*/
//.......................................................................................
/*Understanding the question:
Basically an array is given with 1s and 0s,
Where 1-> A flower is already there
0 -> No flower is there
and a number 'n' is given.
The problem is that we have to check whether the given number 'n' flowers can be 
planted in the given array or not, given that no two flowers (no two 1s) can be 
adjecent to each other.
*/
//.......................................................................................
/*Stratergy:
Okay, let's think about this question.
So basically an array is given with 1 and 0s, 
and if we see that a '1' is not the direct previous or direct next(adjecent) to a 0,
then we are safe to plant a flower there, right?
Also, let's take an example of this array:
[0, 1, 0, 0, 0, 0, 1, 0]
 0, 1, 2, 3, 4, 5, 6, 7  <- Indexes
Here, we can put a flower at either position '3' or '4', right? 
But not in both places together, ofc, otherwise flowers will be placed adjecently.
...So where do we place it?
...Is the question: where can we put flowers? No, right? 
The question just asks whether 'n' flowers can be planted in the given array or not.
So, our focus should be on finding out in how many places of the array can we plant flowers.
So whether we plant it this way: [0, 1, 0, 1, 0, 0, 1, 0]
or this way: [0, 1, 0, 0, 1, 0, 1, 0]
It doesn't matter...we still have only '1' place where we can plant the flower.
.................
So the first thing is that let's take a variable 'm' which can count the no. of free places
where we can plant flowers.
In the end, we'll compare it with n, and if its equal to or greater then n, that would mean
that the array can accomodate those much flowers.
.....
Now, the 2nd thing is that,
while traversing through the array,
we have to find which places have both their direct next and direct previous as '0', right?
So if we find 1, we should simply ignore it, right? Because as it is, 
we can't plant a flower already where a flower is.
.....
The 3rd thing,
Now from here, we're working on places where we have '0'. 
For the very first index (0), we should only check whether the next element is '1' or not.
Similarly, for the very last index of the array, we should check whether the 
previous element was '1' or not, right?
Ex: [0, 0, 1] -> we can plant 1 in index(O).
.....
4th thing,
If the array is just 1 element, and that is 0 -> A flower can be planted
if 1 -> No flower can be planted.
.....
Important Note:
-> Since the array was being given by LeetCode, and we didn't know the size of the 
array it was sending us, I traversed the given array like:
for(size_t i=0; i<array.size(); i++)
-> Updating the array and planting '1' is important in the array, 
   otherwise, we won't be able to check '1' as the 'previous' element for the next element.
Lastly:
-> Since I'm trying to plant the flower as soon as I find a place I can.
   This is the reason why this question is being solved in a 'greedy approach'.
Challenges:
-> I'm trying to enter the elements of the array without giving the size beforehand.
-> Therefore, new concepts learnt: streamline ss(variable)
*/
//.......................................................................................
/*Rough Algorithm Thinking:
m=0; 
if(arr.size()==1){                                  //If array size is just 1
    if (arr[0]==0){m=m+1;}                          //If that element is 0, increasing 1
    if m>=n {return true;} else {return false;}}        
for(i=0, i<arr.size(), i++){ 
    if (arr[i]==1){continue;}                       //Ignoring places already with 'flowers'
    else if(i==0){                                  //For the very first index, checking only next element.
        if (arr[i+1]!=1){m=m+1; arr[i]=1}}             
    else if(i==size-1){                             //For the very last index, checking only previous element.
        if (arr[i-1]!=1){m=m+1; arr[i]=1}} 
    else if(arr[i-1]!=1 && arr[i+1]!=1){            //Checking previous and next for all other elements in the array.
        m=m+1; arr[i]=1} 
    } 
    if m>=n return true;                            //return 'true' if m>=n
*/
//.......................................................................................
//Code:
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        int m = 0;                             //To count the no.of places where we can plant flowers
        //To handle special case of array only having one element.
        if (flowerbed.size() == 1) {                
            if (flowerbed[0] == 0) {           //We can plant flower if the array has '0'
                m = m + 1;
            }

            if (m >= n) {
                return true;
            }
            else {
                return false;
            }
        }                                      //Putting return was important here, otherwise it would have gone to the next step.

        for (size_t i = 0; i < flowerbed.size(); i++) {

            if (flowerbed[i] == 1) {           //To skip those places already with flowers.
                continue;}

            if (i == 0) {                      //If '0' is in the first index
                if (flowerbed[i + 1] != 1) {   //checking only next element
                    m = m + 1;
                    flowerbed[i] = 1;          //updating that place with '1'(a flower)
                }
            }

            else if (i == flowerbed.size() - 1) {  //If '0' is in the last index
                if (flowerbed[i - 1] != 1) {       //checking only previous element
                    m = m + 1;
                    flowerbed[i] = 1;
                }
            }
            //checking for all other elements in the array (previous and next)
            else if (flowerbed[i - 1] != 1 && flowerbed[i + 1] != 1) {
                m = m + 1;
                flowerbed[i] = 1;
            }
        }

        if (m >= n) {
            return true;
        }
        //If n is still greater than m, that means 'n' flowers can't be planted
        return false;
    }
};
int main(){
    vector<int> flowerbed;
    
    string elements;
    cout << "Enter the elements of the array: ";
    getline(cin, elements);

    stringstream ss(elements);  //lets us break that line into individual integers.(Take this string and make it behave like an input stream.)
    
    int element;
    while (ss >> element) {
        flowerbed.push_back(element);
    }

    int n;
    cout<<"Enter 'n': ";
    cin>>n;

    cout<<"The array you entered was: ";
    for (int k : flowerbed) {cout<<k<<" ";}

    Solution solver;
    if (solver.canPlaceFlowers(flowerbed, n)) {
        cout <<endl<<"true" << endl;
    }
    else {
        cout <<endl<<"false" << endl;
    }
}
/*
Results:
Enter the elements of the array: 0 0 1 0 0 0 1
Enter 'n': 2
The array you entered was: 0 0 1 0 0 0 1 
true
.....
Enter the elements of the array: 0 0 1 0 0 0 0 1
Enter 'n': 2
The array you entered was: 0 0 1 0 0 0 0 1 
true
.....
Enter the elements of the array: 0 0 0 0 0 0 0 0 0
Enter 'n': 5
The array you entered was: 0 0 0 0 0 0 0 0 0 
true
.....
Enter the elements of the array: 0 0 0 1
Enter 'n': 3
The array you entered was: 0 0 0 1 
false
.....
Enter the elements of the array: 0
Enter 'n': 1
The array you entered was: 0 
true
.....
Enter the elements of the array: 1
Enter 'n': 0
The array you entered was: 1 
true
*/