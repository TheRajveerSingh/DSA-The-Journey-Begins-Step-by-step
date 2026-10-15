/*Date: 13th oct 2026 - 15th Oct 2026
The following question is from LeetCode 543. Diameter of Binary Tree
Given the root of a binary tree, return the length of the diameter of the tree.
The diameter of a binary tree is the length of the longest path between any two nodes in a tree. 
This path may or may not pass through the root.
The length of a path between two nodes is represented by the number of edges between them.

Example 1:
Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
Example 2:
Input: root = [1,2]
Output: 1
*/
/*
Thinking:
What I'm thinking is, finding the maxDepth.
And then maybe the second maxDepth?
And then combining the two lengths?
But then..from which node? And which two node families?
Because the diameter doesn't always need to starrt from the root, right?
Also,
maxDepth, which we did earlier counted 'no. of nodes'. Here we have to count 'no. of edges'.
Now,
There must also be a particular node in three tree, which acts as the highest point for both right and left Depths, right?
So at that node,
The longest path through that node = right Depth from that node + left Depth from that node?
Now,
From This Node,
If we calculate the no. of nodes down the left depth.
And no. of nodes down the right depth. (Because from that node to any node down: no.of nodes = no.of edges, right? Because see, if a node exist after it, there will exist an edge for it.)
We'll be able to get the the total length by adding the two, right?
So finally,
Let's do one thing,
For each node of the tree, what if we calculate:
left side depth + right side depth. ?
And then which ever is the max, we return it?
*/
#include <iostream>
#include <algorithm>  //For using max
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left; //Let the * be with TreeNode itself as it appears only when TreeNode is written.
    TreeNode* right; //because then, we can write: root, left, right - individually.
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

class Solution{
    int best = 0;
    public:
    int diameterofBinaryTree(TreeNode* root){
        depth(root);
        return best;
    }
    int depth(TreeNode* root){
        if (root == nullptr){ return 0;}
        int left = depth(root->left);
        int right = depth(root-> right);
        best = max(best, left+right);
        return 1 + max(left, right);
    }
};

int main(){
    Solution solver;

    //Ex 1: [1,2,3,4,5] - Answer should be 3 (1-2-4 + 1-3)
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);
    cout<<"Example 1: "<<solver.diameterofBinaryTree(root1)<<endl;

    //Ex 2: [1,2,3,4,5,nullptr, 7, nullptr, nullptr, 10, 11, nullptr, nullptr, nullptr, nullptr, nullptr, 17]
    //Answer should be 6 (1-2-5-11-17 + 1-3-7)
    TreeNode* root2 = new TreeNode(1,
    new TreeNode(2,
        new TreeNode(4), 
        new TreeNode(5,
            new TreeNode(10), 
            new TreeNode(11, nullptr, new TreeNode(17))
        )
    ),
    new TreeNode(3, nullptr, new TreeNode(7))
    );
    cout<<"Example 1: "<<solver.diameterofBinaryTree(root2);

    return 0;
}
/*
Results:
Example 1: 3            
Example 1: 6
*/
/*
Simple thing to keep in mind:
Viariables which are pointers (point to a certain address) : *variable_name
and, Whenever a TreeNode is writen in a function: TreeNode*
while TreeNode* root = TreeNode *root, just for remembering things easily.
also, writing new TreeNode() allocates memory on the heap to store a new node instance.
*/