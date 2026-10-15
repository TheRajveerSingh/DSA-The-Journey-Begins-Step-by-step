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
//A. Either a node doesn't exist so represented by nullptr (no TreeNode is created at all).
//(TreeNode() is just a real node with val = 0 and no children.)
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
    //Check "Learning 4" to find an alternative way to write this same thing.
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
..............
Complexity:
Time: O(n) since every node is visited exactly once.
Space: O(h) for the recursion stack, where h is the height of the tree. Worst case O(n) for a skewed tree (like a linked list).
*/
/*
Now, here's the list of things to learn and understand, one by one:
...............................................
Learning 1 (Basic Definations):
nullptr -> is a value a pointer can hold meaning ‘points to nothing’, so there is no node there.”
Root -> the topmost node with no parent
Leaf node -> the last nodes with no children
binary tree -> a tree structure with atmost 2 children.
A tree Node holds mainly 3 things: 1. A value for itself, 2. A left pointer, 3. A right pointer.
recurrsion -> When a function calls itself inside itself.
base case -> To stop a recursive function to run continuously forever, there has to be a case so that it stops somewhere.
...............................................
Learning 2 (A tree structure):
Here,
Every Node is being called a 'root' when its being used by the function. (root here is just the name of the parameter.)
If the Node doesn't exist -> points to nullptr -> height 0. (base case).
if only the node exists and no children -> Only the value of that node will exist(val), and its left and right pointers exist, but both hold nullptr.
If the node exists with children -> It'll contain its val, and the left and right pointers.
Every pointer may point to another address, again holding the same [val, leftpointer, rightpointer].
...............................................
Learning 3 (pointer, address, * and &):
A variable is something which keeps a value.
And every variable has an address in the memory of the computer.
(Just like a house has people, and that house has an address.)
Now, 
suppose if there's a variable that contains a value, which is actually an address of another variable?
This type of variable is called a 'pointer'. Why? Because, it kinda points to the address of another variable.
So, suppose we have 2 variables:
p and x.
Now, suppose x's value is 5 (int x = 5), and x's address is 1000.
And now we want to change x's value.
So let's make a pointer which points to x's address?
So we do: int *p = &x;
A '*' is used to define a pointer.,
In normal code, *p means ‘go to the address in p and use what’s there’.
A '&' is used to take the address of a variable.
So the above statement means: Let pointer p point to the address of x.
So,
afterwards, if we do: *p=20;
then x's value will change to 20.
But, but, don't be confused.
By mistake, if we do p=20, that means something else.
That'll mean to change the address stored in p.
Because p=20 means changing the value p holds.
In mean, this won't also be happening. Because we can’t accidentally point p at a random address by writing a number. The compiler blocks it.
Valid way to use p:
p = &x;        // OK: p now holds x's address
p = nullptr;   // OK: p now points to nothing
*p = 20;       // OK: go to the address in p and put 20 there (x becomes 20)
...
However, if we really wan't to change the 'address' stored in a pointer, we normally a compiler doesn't allow,
we can write:
p = (int*)20;
which tells the compiler “trust me, treat 20 as an address”.
In short,
pointer - it is a variable which points to the address of another variable.
Now, 
A node (stored at an address) contains several fields: val, left, right.” The address is just the location.
Like here, value in val, right pointer in right, left pointer in left.
So to get the values stored in those data's in that address, we can write:
(*root).val, or (*root).right or (*root).left.
(*root).val gets the val field of the node that root points to. It is not “the value of root”, and it is not the whole thing at the address either.
Also,
(*root).val   ==   root->val
................................................
Learning 4 (Writing the tree in another way):
This same thing:
    TreeNode *root1 = new TreeNode(3);
    root1->left = new TreeNode(9);
    root1->right = new TreeNode(20);
    root1->right->left = new TreeNode(15);
    root1->right->right = new TreeNode(7);
Can also be written as:
    TreeNode *root1 = new TreeNode(3,
        new TreeNode(9),
        new TreeNode(20, new TreeNode(15), new TreeNode(7))
    );
................................................
Learning 5 (What's actually happening):
In the statement: TreeNode* root = new TreeNode(17);
two things are happening here:
1. 'new TreeNode(17)' creates a real node in memory (val = 17, left = nullptr, right = nullptr). 'new' returns the address of that node.
2. That address is stored in the pointer 'root'.
So the pointer doesn’t build anything. It just remembers where the node is.
How nodes link together?
Inside every node, left and right are also pointers. So when we write:
root->left = new TreeNode(6);
a new node for 6 is created, and its address is stored in 17’s left pointer.
So,
A tree is basically nodes in memory, connected by pointers that store each other’s addresses.
Also Note:
While going through the tree down,
Even if a field of value stored in the address to which a pointer 
in pointing to, is already itself a pointer; 
till the time the tree is in use, 
every pointer is given their values when the tree is built, 
and from then on they just hold them.
..................................................
Learning 6 (Distinctions):
root->the current node's address.
root->val → the current node's integer value.
root->left → the address of the left child.
root->left->val → the left child's integer value, assuming the left child exists.
*/