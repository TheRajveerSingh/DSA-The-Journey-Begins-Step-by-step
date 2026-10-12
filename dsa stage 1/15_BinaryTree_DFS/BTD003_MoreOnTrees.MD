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