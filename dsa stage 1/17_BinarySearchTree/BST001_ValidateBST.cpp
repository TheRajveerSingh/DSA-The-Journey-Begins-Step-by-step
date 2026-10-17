/*Date: 15th Oct 2026
This question is from LeetCode 98. Validate Binary Search Tree
Given the root of a binary tree, determine if it is a valid binary search tree (BST).
A valid BST is defined as follows:
The left subtree of a node contains only nodes with keys strictly less than the node's key.
The right subtree of a node contains only nodes with keys strictly greater than the node's key.
Both the left and right subtrees must also be binary search trees.

Example 1:
Input: root = [2,1,3]
Output: true
Example 2:
Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
*/
//.......................................................................................
/*
# TRY 1:
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (root == nullptr){return true;}
        isValidBST(root->left);
        isValidBST(root->right);
        if ((*root).left < root && root< (*root).right){return true;}
        else {return false;}
    }
};
Problems:
1. I'm comparing pointers instead of node values.
It should be: root->left->val
2. Every node in the left subtree must be smaller than the current node, and every node in the right subtree must be greater.
3. The 2 calls return bool values, but I don't do anything with those results.

*/