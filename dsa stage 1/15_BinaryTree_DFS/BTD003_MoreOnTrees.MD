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
queue<TreeNode*> q;   // a queue of node pointers
q.push(root);         // add
q.front();            // look at the first
q.pop();              // remove the first
q.empty();            // is it empty?
q.size();             // how many are in it?

##### The Three DFS Orders
They differ only in where we do the work on the current node.

void preorder(TreeNode* root) {
    if (root == nullptr) return;
    // work on node here           <- BEFORE children
    preorder(root->left);
    preorder(root->right);
}

void inorder(TreeNode* root) {
    if (root == nullptr) return;
    inorder(root->left);
    // work on node here           <- BETWEEN children
    inorder(root->right);
}

void postorder(TreeNode* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    // work on node here           <- AFTER children
}

Example: invertTree (swap first version) is pre-order, but maxDepth is post-order.

##### Patern 1: Returning values/combining values
Suppose we have:
int l = f(root->left)
int r = f(root->right)
return /* combine l, r, root */;

| Problem | Combine |
| :--- | :--- |
| Max depth | `1 + max(l, r)` |
| Count nodes | `1 + l + r` |
| Sum of all values | `root->val + l + r` |
| Balanced check | `abs(l - r) <= 1` |

##### Pattern 2: Comparing two trees at once.
Used in Same Tree, Symmetric Tree, and Subtree of Another Tree. The function takes two pointers:

bool same(TreeNode* p, TreeNode* q) {
    if (p == nullptr && q == nullptr) return true;    // both empty
    if (p == nullptr || q == nullptr) return false;   // only one empty
    if (p->val != q->val) return false;
    return same(p->left, q->left) && same(p->right, q->right);
}

The && and || chaining is very common: return a && b; means “both sides must be true.”

##### Pattern 3: Passing Information Down
Sometimes the child needs to know something from above, so we add a parameter:

void dfs(TreeNode* root, int depth) {
    if (root == nullptr) return;
    // you know your depth here
    dfs(root->left, depth + 1);
    dfs(root->right, depth + 1);
}

Examples: current depth, running sum (Path Sum), allowed min/max range (Validate BST: dfs(root, lo, hi)).

##### Pattern 4: keep a “best so far” outside the function
Used when the answer is not simply what a function returns (Diameter of Binary Tree is the classic case):

class Solution {
    int best = 0;                        // shared by all calls
    int dfs(TreeNode* root) {
        if (root == nullptr) return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);
        best = max(best, l + r);         // update the answer
        return 1 + max(l, r);            // return something different upward
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return best;
    }
};

An alternative is passing a reference: void dfs(TreeNode* root, int& best). This is the & in a declaration that we discussed earlier.

##### Pattern 5: Collect results and backtrack
For “all root-to-leaf paths” style problems:

vector<int> path;
path.push_back(root->val);     // add
// ... recurse ...
path.pop_back();               // undo when returning

##### Pattern 6: Pattern: BFS, level by level
The standard template. The inner loop handles exactly one level at a time:

queue<TreeNode*> q;
q.push(root);
while (!q.empty()) {
    int size = q.size();                 // number of nodes in this level
    for (int i = 0; i < size; i++) {
        TreeNode* node = q.front();
        q.pop();
        if (node->left)  q.push(node->left);
        if (node->right) q.push(node->right);
    }
    // one level finished here (e.g., level++)
}

if (node->left) is shorthand for if (node->left != nullptr), because a pointer is false when it is nullptr.

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
