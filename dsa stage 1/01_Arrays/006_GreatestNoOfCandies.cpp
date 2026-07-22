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
