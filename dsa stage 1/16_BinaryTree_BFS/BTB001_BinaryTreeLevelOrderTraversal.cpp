/*
This question is take from LeetCode Question 102. Binary Tree Level Order Traversal
Given the root of a binary tree, return the level order traversal of its nodes' values. 
(i.e., from left to right, level by level).
Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
Example 2:
Input: root = [1]
Output: [[1]]
Example 3:
Input: root = []
Output: []
*/
/*
As I can see from the output, this is  2D vector, which I don't know how to use yet.
Anyways, let's see how to solve this problem.
Atleast I understand that we take the first root, put it in a vector, and push it into the main vector.
Then we take its children, and push them into a vector, and then push that vector into the main vector.
Then from left to right, we continue to push the children of a particular node into a vector, and then that vector into the main vector.
If there's only 1 child of a node, we'll have to push only that into the vector, and then that vector into the main vector.
If both children are absent(null), we just move on to the next node's children, or stop if there's nothing further.
Okay, 
So what I'm thinking of is,
We have to 
*/