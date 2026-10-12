/*
This question is from LeetCode 226. Invert Binary Tree
Given the root of a binary tree, invert the tree, and return its root.
Example 1
Input: root = [4,2,7,1,3,6,9]
        4                         4
    2      7      ----->      7      2
  1  3    6  9              9   6  3   1 
Output: [4,7,2,9,6,3,1]

Example 2:
Input: root = [2,1,3]
        2                         2
      1   3       ------>      3     1
Output: [2,3,1]
*/
/*
Stratergy:
Okay, what I'm thinking is that as we go down the a branch, 
to interchange the addresses of the pointer they're pointing to.
Like if a left pointer is pointing to AddressA, and right to addressB, swap the addresses of left pointer and right.
And now they point to the addresses opposite.
...Or better, just start from the leaf nodes of the tree, and keep swapping the addresses 
of the pointer till it reaches the parent node.
*/
//................................................................................................................
