/*Date: 11th Oct 2026.
This question is from LeetCode Question 104. Maximum Depth of Binary Tree
And its also my first Tree Problem.
Given the root of a binary tree, return its maximum depth.
A binary tree's maximum depth is the number of nodes along the longest path from the 
root node down to the farthest leaf node.

Example 1:
Input: root = [3,9,20,null,null,15,7]
Strusture:        3
               9    20
                  15   7
Output: 3
Example 2:
Input: root = [1,null,2]
Structure:         1
                     2
Output: 2
*/
/*
Now, from what I've observed:
We first create the structure of the tree. (A common structure for all trees).
We then create the function (the work which has to be done).
And then, in the int main(): We give the real structure of the tree, how it is.
And then call the function upon that tree.
*/
#include <iostream>
#include <algorithm> //For using max
using namespace std;

//Step 1. Creating the structure of a Tree.
//What is the structure of a tree?
//A. Either a node doesn't exist (So the value in the node is = 0, and left and right children don't exist).
//B. Either a node exists but doesn't have any child/Is a lead Node. (So there is a value at that node, but no children.)
//C. A node exists with both children/Only 1 child. (So the node has a value, and both right and left point to an address/The child which doesn't exists point to nullptr.)
//And for every Node: There exists its own value (val), and a left pointer(left child) and a right pointer(right child) which again point to another address.
struct TreeNode {
    int val;
    TreeNode *left;  //Left is the left child of a node, a pointer pointing to the address of a memory whre a value is stored.
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {} //A.
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} //B.
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//Step 2. Writing the function - what to do with the tree
//Note: If the sense of a tree, a "root" means the very first node at the top.
//But here, for the function, "root" here has another sense. Its simply describing the hode we're on right now.
class Solution{
    public:
    int maxDepth(TreeNode *root){
        if (root == nullptr) return 0; //Base Case: If the node doesn't exist(The tree never starts/Its the non existing node after leaf Node of a tree.)
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return 1 + max(leftDepth, rightDepth); //'1' because the current node will be counted, right?
    }
};

//Step 3. Creating the actual tree and pushing it into struct TreeNode and then using the function on it.
int main(){
    Solution sol; //object of Solution class

    //Example 1: [3, 9, 20, null, null, 15, 7]
    TreeNode *root1 = new TreeNode(3);
    root1->left = new TreeNode(9);
    root1->right = new TreeNode(20);
    root1->right->left = new TreeNode(15);
    root1->right->right = new TreeNode(7);
    cout<<"Example 1: "<<sol.maxDepth(root1)<<endl;

    //Example 2: [1, null, 2]
    TreeNode *root2 = new TreeNode(1);
    root2->right = new TreeNode(2);
    cout<<"Example 2: "<<sol.maxDepth(root2)<<endl;

    return 0;
}
/*
Result:
Example 1: 3                
Example 2: 2
*/