/*
Hii, If you've come here, its likely because you went through the file
'DP002_BestTimeToBuyAndSellStockIII.cpp' and needed to find an easier problem 
like that to work upon first. And yes, this file was built by me for the same reason.
That question involves 2 transactions, this one will involve just once.
Once we understand the concept for just 1 transaction here, it'll be easier to work on that too.
This is why this problem is named "BestTimeToBuyAndSellStock".
Okay, This is how the question would look like in this case:
We'll first try understanding the problem, what is it asking for,
and then we'll find understanding the stratergy we might need to implement to solve this problem, okay?
I know we're doing DP Problems for the first time, but as I say,
with the right guidance, there's no need to feel afraid. Okay, here's how it goes:
*/
//.......................................................................................................
/*
Question:
You are given a positive integer array "price" consisting of n elements.
"price" contains prices of a share throughout the day in the order of their occurrences.
When a new price occurs, the old price disappears forever. A transaction for the share is
complete when firstly the share is bought and then sold.
In a transaction where the share is bought at price[j] and sold at price[k],
where j < k, profit for that transaction = price[k] - price[j].
You can use a price only once either to buy or sell the share. Your task is to maximize
the profit in at most 1 transaction and print the same.
Note: If price is empty, print -1. Print 0, if n < 2.

Input Format:
The input consists of two lines:
The first line contains an integer n.
The second line contains n space-separated integers representing the elements in array "price".

Constraints:
0 <= n <= 10^4
1 <= price[i] <= 10^4

Examples:
Input 1:
7
2 30 15 10 8 25 80
Output: 78 (Buy at 2, Sell at 80, Profit = 78)

Input 2:
3
10 1 9
Output: 8 (Buy at 1, Sell at 9, Profit = 8)

Input 3:
5
9 8 7 6 5
Output: 0 (Prices only fall, no profitable transaction possible)
*/
//.......................................................................................................
/*
What is the question asking:
So basically, 
an array named 'price' is given right, with n elements, right?
and those elements are 'stock prices', right?
So what we need to figure out is at what instance can we buy and then sell so that we get 
the max profit, right?
Basically, at what index to buy and then sell so that we get the max profit, right?
Additionally, if the array elements(stocks) only detoriate, better not buy anything,
so profit should be printed as '0'.
If the array is empty, to print '-1'.
...
Thinking 1:
At first glance, we may try to just find the minimum value in the array,
and then the maximum value in the whole array.
Cause literally the difference between the max and min would give the highest profit, right?
But..no. The problem with this approach is that suppose an array is given:
index:  0   1   2
price:  10  1   9
By our approach, we'd get 10-1 = 9.
But that's wrong. As we discussed before, we have to first buy a stock, 
and then sell it, right?
Real profit here would be = 9 - 1 = 8.
...
Thinking 2:
Okay, so what about finding the minimum value in the whole array, and then finding the 
maximum value in the array after that index?
Well..even that approach would have a bug. Suppose take the array:
index:  0   1   2  3
price:  1   10  0  5
Now, here. According to this approach, we'd take 0, and then the max value after that is '5'.
So our profit would be calculated as: 5 - 0 = 5. 
While actually, our prfit should be: 10 - 1 = 9 right?
...
Thinking 3:
Okay, let's do one thing.
Let's traverse through the array, and take the first element as the "mimimum", okay?
Now, as we go through the array, we start noting down the 'difference'(or profit) we're
getting with the elements which are after it (let's say in a variable named 'max_profit).
If a new profit is found, greated than the value already stored in max_profit, 
we'll substitute it, right?
Like:
8 14 17 21
so: 6, 9, 13
(And comparing with only those elements which are larger than it).
So we'll get the max_profit at the end of the array traversal, right?
.
Now, if we find an element which is smaller than the already existing "minimum",
we update our "minimum", right?
Why..because anyways, we're trying to find the 'minimum' in the array.
Secondly, look, suppose an array:
8 14 17 21 2 13 14 15
Here, '2' as being the smallest uptil yet, might be able to give a higher profit if a 
large number comes after it, or even if a number(ex:14 here) repeats itself.
But there's nothing to worry, as the max_profit won't change unless a new profit is larger than it.
*/
//.......................................................................................................
/*
Stratergy:
First take in the 'n' for size of the array. Then take the stocks in the array 'price'.
To traverse through the array 'price' and take the first element as the 'minPrice'.
(minPrice would be used to track the minimum stock value seen in the array uptil each index,
so it'll update if a new minimum value is found in the array.)
Now, the compare the difference between the minimum prices, and all larger elements after it.
This will be stored in 'max_profit' which will only update if a larger profit is found 
than the already stored one.
At the end of the traversal, the max_profit will be printed.
*/