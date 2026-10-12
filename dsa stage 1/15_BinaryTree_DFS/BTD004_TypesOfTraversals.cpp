/*
This program is to understnad how traversals in Trees work.
For DFS, There are three types of traversals in Trees: PreOrder, InOrder, PostOrder.
PreOrder -> First the current node is worked upon, then changes are made in the left and right child.
InOrder -> The node is worked upon between the two children.
PostOrder -> The node is worked upon after the two children.
For BFS, there is the level-Order Traversal
*/
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};

class Solution{
    public:
    void preorder(TreeNode *root){
        if (root == nullptr){return;}
        cout<<root->val<<" ";
        preorder(root->left);
        preorder(root->right);
    }

    void inorder(TreeNode *root){
        if (root == nullptr){return;}
        inorder(root->left);
        cout<<root->val<<" ";
        inorder(root->right);
    }

    void postorder(TreeNode *root){
        if (root == nullptr){return;}
        postorder(root->left);
        postorder(root->right);
        cout<<root->val<<" ";
    }
};

int main(){
    Solution solver;

    //Taking Tree: [1,2,3,4,5]
    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);
    cout<<"PreOrder: ";
    solver.preorder(root1); //No cout since the function return type is void
    cout<<endl;
    cout<<"InOrder: ";
    solver.inorder(root1);
    cout<<endl;
    cout<<"PostOrder: ";
    solver.postorder(root1);
    return 0;
}
/*
Result:
PreOrder: 1 2 4 5 3  (Current -> Left -> right)
InOrder: 4 2 5 1 3   (Left -> Current -> right)
PostOrder: 4 5 2 3 1 (Left -> right -> Current)
*/
//.................................................................................................
/*
Now, 
This is Level-order traversal in BFS.
(Comment out the above code if running this one).
*/
#include <iostream>
#include <queue> // Required for queue
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};

class Solution {
public:
    // 1. Level-Order Traversal (BFS) -> Outputs: 1 2 3 4 5
    void levelorder(TreeNode* root) {
        if (root == nullptr) return;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            cout << current->val << " ";

            // Push left child first so it gets processed before the right child
            if (current->left != nullptr) {
                q.push(current->left);
            }
            if (current->right != nullptr) {
                q.push(current->right);
            }
        }
    }
};
int main(){
    Solution solver;

    //Taking Tree: [1,2,3,4,5]
    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);
    cout<<"LevelOrder: ";
    solver.levelorder(root1);

    return 0;
}
/*
Result:
LevelOrder: 1 2 3 4 5 
*/