##### Statements we’ll use in tree problems:
| Purpose | Statement |
| :--- | :--- |
| Base case (empty tree) | `if (root == nullptr) return nullptr;` (or `return 0;` if the function returns an int) |
| Read a node's data | `root->val`, `root->left`, `root->right` |
| Recurse into children | `f(root->left)`, `f(root->right)` |
| Store a child's answer | `int l = f(root->left);` |
| Combine answers | `1 + max(l, r)`, `1 + r`, `l && r` ,etc. |
| Swap two things | `swap(a, b)` (from `<algorithm>`) |
| Swap two pointers inside a node | `swap(root->left, root->right);` |
| Create a node | `new TreeNode(5)` |
| Check a leaf | `root->left == nullptr && root->right == nullptr` |
| Check "one is null" | `if (p == nullptr \|\| q == nullptr)` |
| Return the root | `return root;` |

##### For BFS (level by level), We may also use a queue:
queue<TreeNode*> q;   // a queue of node pointers<br>
q.push(root);         // add<br>
q.front();            // look at the first<br>
q.pop();              // remove the first<br>
q.empty();            // is it empty?<br>
q.size();             // how many are in it?<br>

##### The Three DFS Orders
They differ only in where we do the work on the current node.<br>

void preorder(TreeNode* root) {<br>
    if (root == nullptr) return;<br>
    // work on node here           <- BEFORE children<br>
    preorder(root->left);<br>
    preorder(root->right);<br>
}<br>

void inorder(TreeNode* root) {<br>
    if (root == nullptr) return;<br>
    inorder(root->left);<br>
    // work on node here           <- BETWEEN children<br>
    inorder(root->right);<br>
}<br>

void postorder(TreeNode* root) {<br>
    if (root == nullptr) return;<br>
    postorder(root->left);<br>
    postorder(root->right);<br>
    // work on node here           <- AFTER children<br>
}<br>

Example: invertTree (swap first version) is pre-order, but maxDepth is post-order.<br>

##### Patern 1: Returning values/combining values
Suppose we have:<br>
int l = f(root->left)<br>
int r = f(root->right)<br>
return /* combine l, r, root */;<br>

| Problem | Combine |
| :--- | :--- |
| Max depth | `1 + max(l, r)` |
| Count nodes | `1 + l + r` |
| Sum of all values | `root->val + l + r` |
| Balanced check | `abs(l - r) <= 1` |

##### Pattern 2: Comparing two trees at once.
Used in Same Tree, Symmetric Tree, and Subtree of Another Tree. The function takes two pointers:<br>

bool same(TreeNode* p, TreeNode* q) {<br>
    if (p == nullptr && q == nullptr) return true;    // both empty<br>
    if (p == nullptr || q == nullptr) return false;   // only one empty<br>
    if (p->val != q->val) return false;<br>
    return same(p->left, q->left) && same(p->right, q->right);<br>
}<br>

The && and || chaining is very common: return a && b; means “both sides must be true.”<br>

##### Pattern 3: Passing Information Down
Sometimes the child needs to know something from above, so we add a parameter:<br>

void dfs(TreeNode* root, int depth) {<br>
    if (root == nullptr) return;<br>
    // you know your depth here<br>
    dfs(root->left, depth + 1);<br>
    dfs(root->right, depth + 1);<br>
}<br>

Examples: current depth, running sum (Path Sum), allowed min/max range (Validate BST: dfs(root, lo, hi)).<br>

##### Pattern 4: keep a “best so far” outside the function
Used when the answer is not simply what a function returns (Diameter of Binary Tree is the classic case):<br>

class Solution {<br>
    int best = 0;                        // shared by all calls<br>
    int dfs(TreeNode* root) {<br>
        if (root == nullptr) return 0;<br>
        int l = dfs(root->left);<br>
        int r = dfs(root->right);<br>
        best = max(best, l + r);         // update the answer<br>
        return 1 + max(l, r);            // return something different upward<br>
    }<br>
public:<br>
    int diameterOfBinaryTree(TreeNode* root) {<br>
        dfs(root);<br>
        return best;<br>
    }<br>
};<br>

An alternative is passing a reference: void dfs(TreeNode* root, int& best). This is the & in a declaration that we discussed earlier.<br>

##### Pattern 5: Collect results and backtrack
For “all root-to-leaf paths” style problems:<br>

vector<int> path;<br>
path.push_back(root->val);     // add<br>
// ... recurse ...<br>
path.pop_back();               // undo when returning<br>

##### Pattern 6: Pattern: BFS, level by level
The standard template. The inner loop handles exactly one level at a time:<br>

queue<TreeNode*> q;<br>
q.push(root);<br>
while (!q.empty()) {<br>
    int size = q.size();                 // number of nodes in this level<br>
    for (int i = 0; i < size; i++) {<br>
        TreeNode* node = q.front();<br>
        q.pop();<br>
        if (node->left)  q.push(node->left);<br>
        if (node->right) q.push(node->right);<br>
    }<br>
    // one level finished here (e.g., level++)<br>
}<br>

if (node->left) is shorthand for if (node->left != nullptr), because a pointer is false when it is nullptr.<br>

##### Small helpers you’ll keep seeing

| Statement | Use |
| :--- | :--- |
| `max(a, b)`, `min(a, b)` | combining answers |
| `abs(x)` | height difference |
| `swap(a, b)` | invert tree |
| `INT_MIN`, `INT_MAX`, `LONG_MIN` | initial bounds (from `<climits>`) |
| `vector<int> v; v.push_back(x);` | collecting values |
| `v.back()`, `v.pop_back()` | backtracking |
| `stack<TreeNode*> st;` | iterative DFS |
| `unordered_map<int,int> m;` | lookups (building trees, path sums) |
| `to_string(x)` | path strings |

##### Which pattern to reach for:

| The problem says... | Think |
| :--- | :--- |
| "height / depth / count / sum" | return a value and combine (section 2) |
| "same / symmetric / subtree" | two pointers at once (section 3) |
| "path sum / valid BST" | pass info down (section 4) |
| "diameter / max path sum" | outside variable (section 5) |
| "all paths" | backtracking (section 6) |
| "level order / by level / right side view" | BFS (section 7) |

___________________________________________________________________________________________________________

##### Some Basic Knowledges:
1. What is a TreeNode?<br>
In arrays and strings, we used types that already exist: int, char, string, vector<int>. <br>
A vector is a data type already designed to hold many ints.<br>
Now,<br>
TreeNode is a type that we (or LeetCode) designs ourself. C++ lets us do that with struct:<br>
struct TreeNode {<br>
    int val;<br>
    TreeNode *left;<br>
    TreeNode *right;<br>
};<br>
This says: “a thing called TreeNode is a bundle of three pieces: <br>
an int named val, and two pointers named left and right.”<br>
Now,<br>
A struct is only a blueprint, like the plan of a house. <br>
No house exists yet. A house appears when we build one from the plan:<br>
TreeNode a;      // builds one actual node (a "house")<br>
TreeNode b;      // builds another, completely separate one<br>

Each built node is called an object (or an instance). <br>
Every object has its own val, its own left, and its own right.<br>
Simple Analogy: int is to 5 what TreeNode is to “a particular node in our tree”<br>.

2. Difference between TreeNode, TreeNode*, and TreeNode(...)<br>

| Written as | What it is |
| :--- | :--- |
| `TreeNode` | the type: “a node” |
| `TreeNode *root` | a pointer variable that can hold the address of the node |
| `TreeNode(17)` | a constructor call: the instruction that builds a node with val 17 |

The constructor:<br>
A constructor is a special function inside the struct. <br>
It runs automatically at the moment a node is built and sets up its starting values.<br> 
We can recognize it by two things: it has the same name as the struct, and it has no return type.<br>

3. Traversal in Trees
In an array, visiting every element is easy: for (int i = 0; i < n; i++). <br>
However, a tree has no indexes. <br>
We can only reach a node by following pointers from the root. <br>
So we need a systematic way to visit every node exactly once. That is called a traversal.<br>

The recursive code for every traversal has the same skeleton:<br>
void visit(TreeNode *root) {<br>
    if (root == nullptr) return;<br>
    visit(root->left);<br>
    visit(root->right);<br>
}<br>

Each node has three moments: <br>
before going into its left family, <br>
between the left and right families, <br>
and after both. <br>
The three traversals differ only in when we “use” the node (print it, swap it, add it):<br>

Ex: Let's take a tree: [1,2,3,4,5]<br>
               1<br>
            2     3<br>
          4   5<br>

| Traversal | Output | Reasoning |
| :--- | :--- | :--- |
| Preorder | `1 2 4 5 3` | 1 first, then the whole left family (2 4 5), then 3 |
| Inorder | `4 2 5 1 3` | left family (4 2 5), then 1, then 3 |
| Postorder | `4 5 2 3 1` | left family (4 5 2), right family (3), then 1 last |

Examples of earlier problems and what used which:<br>
maxDepth is postorder: it needs the children’s answers before it can compute its own.<br>
invertTree (swap first version) is preorder: it acts on the node, then recurses.<br>

Note: In a binary search tree (left values smaller, right values larger), inorder prints the values in sorted order.<br>

##### Here are some new things we'd be using while working with trees:<br>
1. Recursion. 
A function calling itself on a smaller piece. Earlier topics such as Arrays used loops with indexes. <br>
Trees have no indexes, so recursion replaces the loop. This is the biggest mindset shift. <br>
Pointers and nullptr.
2. Structs and constructors.
3. The call stack. 
Each recursive call waits for the ones it started.  <br>
Space complexity for trees is usually O(height) because of this waiting line. <br>
4. Queue and stack containers. 
queue<TreeNode*> for level-by-level work,  <br>
stack<TreeNode*> for iterative DFS.  <br>
Note the element type is TreeNode *: the container holds addresses, not copies of nodes. <br>
5. Class variables. 
Sometimeswe keep a variable like int best = 0; <br>
inside the class so every recursive call can update it, instead of passing it around.<br>
6. References (int &x) as parameters, another way to let calls share one variable.<br>
