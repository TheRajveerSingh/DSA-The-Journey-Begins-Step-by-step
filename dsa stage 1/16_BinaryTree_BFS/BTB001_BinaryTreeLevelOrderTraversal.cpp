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
Then from left to right, we continue to push the children of the nodes above into a vector, and then that vector into the main vector.
Basically, 
At every level, all available nodes are put in a single vector.
Ex:  [3,9,20,,4,5,15,7]  ---> [[3],[9,20],[4,5,15,7]]
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

class Solution{
    public:
    vector<vector<int>> levelOrder(TreeNode* root){
        vector<vector<int>> ans;

        if (root == nullptr){return ans;}

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size(); //For each queue of a particular level, getting its size, so that only that number of elements from the queue are added.
            vector<int> level; //Making the vector 'level' for storing the elements of a particular level from the queue (the size tells us how many elements to take from the queue).

            //To process all nodes at the 'current level' from the queue
            for (int i = 0; i<size; i++){
                TreeNode* node = q.front();
                q.pop(); //After an element from the queu is added, to pop it, so that the next element can be taken.

                //Storing the current node's value
                level.push_back(node->val);

                //Adding existing children to the queue
                if (node->left !=nullptr){
                    q.push(node->left);
                }

                if (node->right != nullptr){
                    q.push(node->right);
                }
            }
            ans.push_back(level);
        }
        return ans;
    }
};

int main(){
    Solution solver;

    //Example 1: [[3], [9,20], [15,7]]
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(9);
    root1->right = new TreeNode(20);
    root1->right->left = new TreeNode(15);
    root1->right->right = new TreeNode(7);
    cout<<"Example 1:\n";
    vector<vector<int>> ans1 = solver.levelOrder(root1); //Remember, that when a function is returning a vector, we have to store it in a vector again, and traverse through it to print the answers?
    for(int i=0; i<ans1.size(); i++){
        cout<<"[";
        for(int j=0; j<ans1[i].size(); j++){
            cout<<ans1[i][j];
            if(j<ans1[i].size() - 1){ cout<<",";}
        }
        cout<<"]"<<endl;
    }

    //Example 2: [[3], [9,20], [4,8,15,7]]
    TreeNode* root2 = new TreeNode(3);
    root2->left = new TreeNode(9);
    root2->right = new TreeNode(20);
    root2->left->left = new TreeNode(4);
    root2->left->right = new TreeNode(8);
    root2->right->left = new TreeNode(15);
    root2->right->right = new TreeNode(7);
    cout<<"Example 2:\n";
    vector<vector<int>> ans2 = solver.levelOrder(root2);
    for(int i=0; i<ans2.size(); i++){
        cout<<"[";
        for(int j=0; j<ans2[i].size(); j++){
            cout<<ans2[i][j];
            if(j<ans2[i].size() - 1){ cout<<",";}
        }
        cout<<"]"<<endl;
    }

    return 0;
}
/*
Result:
Example 1:
[3]
[9,20]
[15,7]
Example 2:
[3]
[9,20]
[4,8,15,7]
*/