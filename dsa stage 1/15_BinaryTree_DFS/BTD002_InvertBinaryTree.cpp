/*Date: 12th Oct 2026
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

For example, for [2,1,3]
Before the swap at node 2:
2->left  = address of node 1
2->right = address of node 3

After swap(root->left, root->right):
2->left  = address of node 3
2->right = address of node 1
*/
//................................................................................................................
#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{
    public:
    TreeNode *invertTree(TreeNode *root){ //A function returning a pointer.
        if (root == nullptr){return nullptr;} //We cannot return 0, as this function returns a pointer. So we return 'nullptr'.(Base Case)

        swap(root->left, root->right); //Swapping the left and right pointerrs
        // invert the whole family under this node and give me back the node”

        invertTree(root->left); //Now, we again put the left family to the function, so its right and left pointers can be swapped.
        invertTree(root->right); //Both of these statements are part of recurrsion.

        return root; //returning the node
    }
};
//At each node, three things happen:
//Swap its two child pointers.
//Ask each child to invert its own family (recursion does this).
//Return the node itself.

int main(){
    Solution solver;

    //Ex 1: [4,2,7,1,3,6,9]
    TreeNode *root1 = new TreeNode(4);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(7);
    root1->left->left = new TreeNode(1);
    root1->left->right = new TreeNode(3);
    root1->right->left = new TreeNode(6);
    root1->right->right = new TreeNode(9);
    cout<<"Ex 1: "<<solver.invertTree(root1)<<endl;

    //Ex 2: [2,1,3]
    TreeNode *root2 = new TreeNode(2);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(3);
    cout<<"Ex 2: "<<solver.invertTree(root2)<<endl;

    return 0;
}
/*
Result 1:
Ex 1: 0x1f12a2f3510                     
Ex 2: 0x1f12a2f9ca0
..........................Hmm, this is not the output I expected,
*/
//.............................................................................................
/*
Suppose I wanted to go from down to up, from children to parent, I could have done:
TreeNode* l = invertTree(root->left);
TreeNode* r = invertTree(root->right);
root->left = r;
root->right = l;
return root;
*/