/*
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
..............................................
First of all, 
thing is that in a BST, its not about only checking whether the immidiate children are folloing the rule
(left lesser than node, and right greater than node),
but also that, After every node, its left family, should never have any number above or equal to that node.
and its right family, should never have any number lower or equal to that node.
So let's do one thing,
For every node, we'll pass it to another function called 'check' along with two other things:
Its highest allowed limit, and its lowest allowed limit.
Base Case - if root == nullptr - return true
If a root's value is lesser than its lower limit, or higher than its high limit, we return false.
*/
#include <iostream>
#include <climits> //For using LLONG_MIN, and LLONG_MAX
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution{
    public:
    bool isValidBST(TreeNode* root){
        return check(root, LLONG_MIN, LLONG_MAX);
    }

    private:
    bool check(TreeNode* root, long long low, long long high){

        if (root == nullptr){return true;} //Base Case

        if (root->val<=low || root->val>=high){return false;} //To check if current node is between its limits or not

        bool lhs = check(root->left, low, root->val); // the value at the left of a node should not be higher than the current node's value
        bool rhs = check(root->right, root->val, high); //the value at the right of a node should be higher than the current node's value

        return lhs && rhs; //So basically, if we reach till the very end of our tree, and get 'true' as returned, that'll mean our BST is valid.
    }
};

int main(){
    Solution solver;

    //Example 1: [5, 3, 7, 1, 4, 6, 8]
    TreeNode* root1 = new TreeNode(5);
    root1->left = new TreeNode(3);
    root1->right = new TreeNode(7);
    root1->left->left = new TreeNode(1);
    root1->left->right = new TreeNode(4);
    root1->right->left = new TreeNode(6);
    root1->right->right = new TreeNode(8);
    bool print1 = solver.isValidBST(root1); 
    cout<< "Example 1: ";
    if (print1){cout<<"true";}
    else{cout<<"false";}

    cout<<endl; 

    //Example 2: [5,1,4,null,null,3,6]
    TreeNode* root2 = new TreeNode(5);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(4);
    root2->right->left = new TreeNode(3);
    root2->right->right = new TreeNode(6);
    bool print2 = solver.isValidBST(root2); 
    cout<< "Example 2: ";
    if (print2){cout<<"true";}
    else{cout<<"false";}
    
    return 0;
}
/*
Result:
Example 1: true
Example 2: false
*/