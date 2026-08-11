// So I came across a question during one of my placement exams (7-11), and here's how it was:
/*
Question:
You are given a positive integer array "price" consisting of n elements. 
"price" contains prices of a share throughout the day in the order of their occurrences. 
When a new price occurs, the old price disappears forever. A transaction for the share is 
complete when firstly the share is bought and then sold. 
In a transaction where the share is bought at price[j] and sold at price[k], 
where j < k, profit for that transaction = price[k] - price[j]. 
You can use a price only once either to buy or sell the share. Your task is to maximize 
the profit in at most 2 transactions and print the same. Transaction 2 starts only when 
transaction 1 is completed. 
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
Output: 100 (Trans 1: 30 - 2 = 28, Trans 2: 80 - 8 = 72. Total: 100)
Input 2:
8
10 5 22 65 8 75 90 80
Output: 142 (Trans 1: 65 - 5 = 60, Trans 2: 90 - 8 = 82. Total: 142)
*/
//....................................................................................................
// Stratergy: