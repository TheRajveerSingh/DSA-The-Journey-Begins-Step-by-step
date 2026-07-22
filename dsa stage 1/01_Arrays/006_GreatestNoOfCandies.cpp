/*
This question is based upon LeetCode Q.1431: "Kids with Greatest Number of Candies".
The question is as follows:
There are n kids with candies. You are given an integer array candies, 
where each candies[i] represents the number of candies the ith kid has, 
and an integer extraCandies, denoting the number of extra candies that you have.
Return a boolean array result of length n, where result[i] is true if, 
after giving the ith kid all the extraCandies, they will have the greatest number of 
candies among all the kids, or false otherwise.
Note that multiple kids can have the greatest number of candies.
Example 1:
Input: candies = [2,3,5,1,3], extraCandies = 3
Output: [true,true,true,false,true] 
Explanation: If you give all extraCandies to:
- Kid 1, they will have 2 + 3 = 5 candies, which is the greatest among the kids.
- Kid 2, they will have 3 + 3 = 6 candies, which is the greatest among the kids.
- Kid 3, they will have 5 + 3 = 8 candies, which is the greatest among the kids.
- Kid 4, they will have 1 + 3 = 4 candies, which is not the greatest among the kids.
- Kid 5, they will have 3 + 3 = 6 candies, which is the greatest among the kids.
*/
//.........................................................................................
/*
Let's try figuring out the stratergy to solve this question, step by step..
First,
I need to take an array for candies from the user, right?
So we'll define that, by using 'vector' as it allows using functions like max_element(), sort(), and reverse().
We'll also take the number for 'ExtraCandies'

Second,
We have to send these values to a function to solve the problem right?
So we create a function, and since it should return an array with bool(true/false), 
let us define the function as vector<bool> type. Okay, done.

Third,
Now, see the question, what do we have to do?
Basically we have to check whether if we give the extra candies to each kid,
(each i in the array candies),
whether it'll be the maximum amongst all the kids then or not, right? 
(That ith kid when given ExtraCandies should be the maximum value n the whole array)
So what do we do?
First of all let's create a new array to contain the bool values.
Okay, now, we would go through the whole array of candies, and find the max ith value.
Then,
For each i in the candies array,
if i + extracandies >= max_value(candies), we would push 'true', otherwise 'false' right?
Why? because that's what we needed to find, right? 
If after we give ExtraCandies to each ith kid, whether they'll have the max in the array 'candies'
So if their value is greater or equal to the max value of the array, ofc they'll be the greatest in the whole array, right?
Okay, moving on,

Fourth,
Now, we return that array which we got (that bool vector).
But that array would be in 1 and 0 form, right? 
So, let's do one thing,
To match the expected output for this question, we'll iterate through the returned vector array,
and print true for 1, and false for 0, okay?

And done..
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(const vector<int>& candies, int extraCandies) { //remember our technique to use call-by-reference and using const to save time, and not even change the value? 
        int max_candies = *max_element(candies.begin(), candies.end()); //An '*' is to be used as without it, the actual location for the i will be given. '*' returns the value in that location
        vector<bool> result;  //to create a result array to store the output boolean array
        
        for (int i : candies) {                                       //for i in candies array
            if (i + extraCandies >= max_candies) {   //Alternatively we can use this if-else's short form: 
            result.push_back(true);                  //result.push_back(i + extraCandies >= max_candies);
            } else {                                 //cause it'll push 1 or 0 accordingly by default.
            result.push_back(false);
            }
        }
        
        return result;
    }
};

int main() {
    int n;
    cout << "Enter the number of kids: ";  //Taking the size of the array
    cin >> n;

    vector<int> candies(n);    //Creating the array 

    cout << "Enter the candies for each kid: ";  //Taking values in the array
    for (int i = 0; i < n; i++) {
        cin >> candies[i];
    }

    int extraCandies;
    cout << "Enter the number of extra candies: ";
    cin >> extraCandies;

    Solution solver;
    vector<bool> result = solver.kidsWithCandies(candies, extraCandies);

    // Just by fetching the returned array by the function, it'll give 1 or 0, and not 'true' and 'false', this is why this step:
    cout << "\nResult: [ ";
    for (bool val : result) {                    //for val in result array
        cout << (val ? "true" : "false") << " "; //Short form of a if-else
    }
    cout << "]" << endl;

    return 0;
}
/*
Result:
Enter the number of kids: 6          
Enter the candies for each kid: 2 3 5 1 3 4
Enter the number of extra candies: 2
Result: [ false true true false true true ]
*/
/*
What I learnt:
1. The *max_element(arr start, arr end) for finding the maximum element in an array (by the header <algorithm>)
2. Without the '*', the variable stores the location of the max_element, and not the value;
3. In some case, even if we want to store the location, the variable can be defined as type 'auto'
   example: auto max_location = max_element(candies.begin(), candies.end());
4. If there's an if-else statement for only 1 condition, and we need to return bool values
   we can do it by just writing: return(condition), and no need for if-else; as by default true or false
   for that condition will be returned. (As we can see in line 73)

What I revised:
1. Concept of saving time: The function taking the parameter as 'call-by-reference (&)' and then using 'const' so that it doesn't change by mistake
2. The short form of an if-else statement: (cal>5 ? "if true, text written here will print" : "if false, this will")
3. For a function to return a dynamic array of bool type, it should be of type: vector<bool>
*/