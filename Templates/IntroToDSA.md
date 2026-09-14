### Core Patterns & Data Structures Breakdown

**01. Arrays**

* **Definition:** A contiguous block of memory storing elements of the same type under fixed indices.
* **Why & When:** Provides $O(1)$ random access by index and cache locality; used when input size is bounded or index-based lookups dominate.
* **Problems:** Two Sum, Rotate Array, Product of Array Except Self.

**02. Strings**

* **Definition:** A sequence of characters stored contiguously (often immutable depending on language).
* **Why & When:** Models text processing; critical for anagrams, parsing, and pattern matching.
* **Problems:** Valid Anagram, Longest Common Prefix, String Compression.

**03. Two Pointers**

* **Definition:** Iterating through linear sequences using two index markers moving toward each other, outward, or in tandem.
* **Why & When:** Reduces $O(N^2)$ brute-force search space down to $O(N)$ when data is ordered or sorted.
* **Problems:** Two Sum II (Sorted Array), 3Sum, Container With Most Water, Trapping Rain Water.

**04. Sliding Window**

* **Definition:** A dynamic or fixed range defined by two pointers moving in the same direction over a sequence.
* **Why & When:** Eliminates recomputing sums/counts for overlapping subarrays or substrings, turning $O(N \cdot K)$ into $O(N)$.
* **Problems:** Longest Substring Without Repeating Characters, Minimum Size Subarray Sum, Sliding Window Maximum.

**05. Prefix Sum**

* **Definition:** A precomputed array where each entry stores the cumulative sum from index $0$ to $i$.
* **Why & When:** Computes any arbitrary range sum query in $O(1)$ time after an $O(N)$ preprocessing step.
* **Problems:** Subarray Sum Equals K, Range Sum Query - Immutable, Find Pivot Index.

**06. HashMap & HashSet**

* **Definition:** Hash-table implementations mapping unique keys to values (Map) or storing distinct keys (Set).
* **Why & When:** Provides average $O(1)$ lookups, insertions, and deletions to track frequencies, visited states, and pairings.
* **Problems:** Two Sum, Group Anagrams, Longest Consecutive Sequence.

**07. Stack**

* **Definition:** A Last-In, First-Out (LIFO) linear data structure.
* **Why & When:** Tracks state history where the most recently added item needs to be evaluated first; mimics recursive call stacks.
* **Problems:** Valid Parentheses, Evaluate Reverse Polish Notation, Min Stack.

**08. Monotonic Stack**

* **Definition:** A stack where elements are strictly kept in monotonic increasing or decreasing order.
* **Why & When:** Finds the **Next Greater / Smaller Element** to the left or right in $O(N)$ total time instead of $O(N^2)$.
* **Problems:** Daily Temperatures, Next Greater Element, Largest Rectangle in Histogram.

**09. Queue**

* **Definition:** A First-In, First-Out (FIFO) linear data structure.
* **Why & When:** Processes items in strict chronological order; serves as the engine for BFS and buffering systems.
* **Problems:** Implement Stack using Queues, Design Circular Queue, Number of Recent Calls.

**10. Linked List**

* **Definition:** Nodes composed of data and pointers scattered arbitrarily in memory.
* **Why & When:** Provides $O(1)$ insertion and deletion at known positions without reallocating contiguous memory.
* **Problems:** Reverse Linked List, Merge Two Sorted Lists, Reorder List.

**11. Fast & Slow Pointers (Floyd’s Cycle Finding)**

* **Definition:** Two pointers traversing an iterable structure at different velocities (typically $1\times$ and $2\times$).
* **Why & When:** Detects periodic cycles or finds midpoints in a single pass without extra memory ($O(1)$ space).
* **Problems:** Linked List Cycle I & II, Middle of the Linked List, Happy Number.

**12. Recursion & Backtracking**

* **Definition:** Algorithmic technique that builds candidates incrementally and abandons ("backtracks") a path as soon as it violates constraints.
* **Why & When:** Exhaustively searches combinatorial state spaces (permutations, subsets, paths).
* **Problems:** Subsets, Permutations, N-Queens, Word Search, Sudoku Solver.

**13. Bit Manipulation**

* **Definition:** Direct operations on binary representations of integers using AND, OR, XOR, NOT, and bit shifts.
* **Why & When:** Achieves constant-time space/state compression, parity checks, and bitmask tracking in $O(1)$ auxiliary space.
* **Problems:** Single Number, Number of 1 Bits, Counting Bits, Reverse Bits.

**14. Binary Search**

* **Definition:** Divide-and-conquer search algorithm discarding half of the search space at each iteration.
* **Why & When:** Searches sorted arrays or monotonic answer spaces in $O(\log N)$ time.
* **Problems:** Search in Rotated Sorted Array, Find Minimum in Rotated Sorted Array, Koko Eating Bananas.

**15. Binary Tree DFS**

* **Definition:** Deep tree exploration using preorder, inorder, or postorder traversals via recursion or an explicit stack.
* **Why & When:** Traverses down to leaf paths, verifies subtrees, or computes depths/heights.
* **Problems:** Maximum Depth of Binary Tree, Invert Binary Tree, Lowest Common Ancestor.

**16. Binary Tree BFS**

* **Definition:** Level-order exploration using a FIFO queue.
* **Why & When:** Processes nodes horizontal level by horizontal level; computes the shortest path in unweighted tree graphs.
* **Problems:** Binary Tree Level Order Traversal, Binary Tree Right Side View, Zigzag Level Order Traversal.

**17. Binary Search Tree (BST)**

* **Definition:** A binary tree where the left subtree contains values strictly smaller than the root, and the right subtree contains values strictly greater.
* **Why & When:** Keeps data dynamically sorted while offering average $O(\log N)$ lookups, insertions, and predecessor/successor operations.
* **Problems:** Validate Binary Search Tree, Kth Smallest Element in a BST, Delete Node in a BST.

**18. Trie (Prefix Tree)**

* **Definition:** A tree data structure dedicated to storing and retrieving strings where nodes represent characters.
* **Why & When:** Handles prefix queries, autocompletion, and dictionary lookups in $O(L)$ time (where $L$ is word length), independent of dictionary size.
* **Problems:** Implement Trie (Prefix Tree), Design Add and Search Words Data Structure, Word Search II.

**19. Graphs DFS**

* **Definition:** Exploring graph paths until a dead-end or visited node is reached, keeping track of cycles via visited sets.
* **Why & When:** Detecting cycles, finding connected components, and computing topological sorts.
* **Problems:** Course Schedule, Number of Connected Components, Clone Graph.

**20. Graphs BFS**

* **Definition:** Layer-by-layer exploration of nodes radiating outwards from source vertices.
* **Why & When:** Finds the **shortest path in unweighted graphs**; models wave propagation.
* **Problems:** Word Ladder, Rotting Oranges, Shortest Path in Binary Matrix.

**21. Graphs / Grids DFS & BFS**

* **Definition:** Treating 2D matrices as implicit graphs where each cell $(r, c)$ is a node with up to 4 or 8 directional edges.
* **Why & When:** Island counting, flood fill, spatial reachability, and maze routing.
* **Problems:** Number of Islands, Max Area of Island, Pacific Atlantic Water Flow.

**22. Heap / Priority Queue**

* **Definition:** A complete binary tree satisfying the heap property (parent is always $\le$ or $\ge$ its children).
* **Why & When:** Provides $O(1)$ access to the extreme element (min or max) with $O(\log N)$ push/pop operations.
* **Problems:** Merge K Sorted Lists, Find Median from Data Stream, Task Scheduler.

**23. Top-K Pattern**

* **Definition:** Maintaining a min-heap or max-heap of fixed size $K$ while processing an unsorted stream of $N$ items.
* **Why & When:** Finds the $K$ largest/smallest items in $O(N \log K)$ time and $O(K)$ space instead of sorting the whole list in $O(N \log N)$.
* **Problems:** Kth Largest Element in an Array, Top K Frequent Elements, K Closest Points to Origin.

**24. Intervals**

* **Definition:** Problems involving start and end boundaries $[start, end]$ representing ranges or time slots.
* **Why & When:** Solves overlap, intersection, and scheduling conflicts, typically by sorting by start time first.
* **Problems:** Merge Intervals, Non-overlapping Intervals, Meeting Rooms I & II.

**25. Greedy**

* **Definition:** An algorithmic paradigm making locally optimal choices at each step hoping to reach a global optimum.
* **Why & When:** Solves optimization problems when the greedy choice property and optimal substructure can be proven.
* **Problems:** Jump Game, Gas Station, Assign Cookies.

**26. Dynamic Programming (1D)**

* **Definition:** Breaking a problem into sequential, overlapping subproblems with one changing parameter/state variable.
* **Why & When:** Turns exponential-time recursive decisions into $O(N)$ linear-time lookups using memoization or bottom-up tabulation.
* **Problems:** Climbing Stairs, House Robber, Coin Change, Longest Increasing Subsequence.

**27. Dynamic Programming (Multidimensional)**

* **Definition:** Tabulating subproblems constrained by two or more state variables (e.g., indices, grid coordinates, remaining capacity).
* **Why & When:** Evaluates pairwise string alignments, 2D grid path choices, or knapsack weight/item decisions.
* **Problems:** Longest Common Subsequence, Edit Distance, Unique Paths, 0/1 Knapsack.

---

### Common Interview Confusions

| Pair | Core Difference | Interview Implication |
| --- | --- | --- |
| **Binary Search vs. Binary Search Tree (BST)** | **Binary Search** is an *algorithm* executed over a random-access collection (like an array) or monotonic monotonic range. **BST** is a *data structure* composed of linked nodes. | Binary Search requires $O(1)$ index jumps ($O(\log N)$ time, $O(1)$ space). BST searches follow pointer dereferences and degrade to $O(N)$ if unbalanced. |
| **Two Pointers vs. Sliding Window** | **Two Pointers** move independently, outward, or inward (e.g., meeting in the middle for pairings). **Sliding Window** involves both pointers moving in the *same direction* to define a contiguous range. | Use Two Pointers on sorted arrays for combinations ($A[i] + A[j]$). Use Sliding Window for continuous subarrays/substrings. |
| **Queue vs. Priority Queue** | A **Queue** is strictly FIFO (order determined solely by arrival time). A **Priority Queue** dequeues elements based on numerical priority/weight. | Queue uses $O(1)$ standard enqueues/dequeues. Priority Queue incurs $O(\log N)$ heap-sift time per operation. |
| **Tree BFS vs. Graph BFS** | Trees are acyclic and connected; graphs contain cycles and disconnected components. | Graph BFS **must** track a `visited` set to prevent infinite loops. Tree BFS does not require a `visited` set unless edges are bidirectional. |
| **Greedy vs. Dynamic Programming** | **Greedy** commits to the single best local choice and never reconsiders. **DP** evaluates all overlapping choices and caches intermediate results. | If local choices can invalidate optimal future choices (e.g., Coin Change with arbitrary denominations), Greedy fails and DP is required. |
| **Backtracking vs. Dynamic Programming** | **Backtracking** returns *all valid configurations* (all subsets, permutations). **DP** computes *aggregate metrics* (min cost, max value, total count). | If the problem asks for "return all paths", use Backtracking. If it asks for "number of paths" or "shortest path weight", use DP. |

### A DSA Table

| Data Structures *(Where data lives)* | Algorithms *(How data is processed)* | Problem-Solving Patterns / Concepts *(How problems are approached)* |
| --- | --- | --- |
| **Arrays / Vectors** | **Binary Search** | **Two Pointers** (inward, outward, parallel) |
| **Strings** | **Sorting** (QuickSort, MergeSort, HeapSort) | **Sliding Window** (fixed vs. dynamic size) |
| **Linked Lists** (Singly, Doubly) | **Tree Traversal** (Pre/In/Post-order, Level-order) | **Prefix Sum** / Difference Array |
| **Stacks & Monotonic Stacks** | **Graph Traversals** (DFS, BFS) | **Fast & Slow Pointers** (Floyd's Cycle) |
| **Queues & Deques** | **Shortest Path** (Dijkstra, Bellman-Ford) | **Top-K Elements** (Fixed-size Min/Max Heap) |
| **Hash Maps & Hash Sets** | **Topological Sort** (Kahn’s Algorithm, DFS) | **Intervals** (Merge, insert, overlap check) |
| **Trees & BSTs** | **Minimum Spanning Tree** (Kruskal’s, Prim’s) | **Recursion & Backtracking** (Pruning state space) |
| **Heaps / Priority Queues** | **Cycle Detection** (Union-Find / Tarjan’s) | **Divide & Conquer** (Subproblem merge) |
| **Graphs** (Adjacency Matrix/List) | **Bitwise Computations** (Masking, parity) | **Greedy Paradigm** (Local optimum choices) |
| **Tries** (Prefix Trees) | **String Matching** (KMP, Rabin-Karp) | **Dynamic Programming** (1D/2D Tabulation & Memoization) |
| **Disjoint Set Union (DSU)** | **Matrix Traversal** (Flood Fill, Direction vectors) | **Bit Manipulation Tricks** (XOR cancellation, bitmask DP) |

### 5 Algorithms for Graphs

| Algorithm | Primary Purpose | Key Strength / Core Characteristic |
|---|---|---|
| Dijkstra | Single-Source Shortest Path | Blazing fast O((V+E) log V) but fails with negative weights. |
| Bellman-Ford | Single-Source Shortest Path | Slower, but safely handles negative weights and cycles. |
| Floyd-Warshall | All-Pairs Shortest Path | Finds all paths at once using simple matrix loops. |
| Kruskal | Minimum Spanning Tree (MST) | Edge-based; brilliant when edges are already sorted. |
| Prim | Minimum Spanning Tree (MST) | Vertex-based; superior for dense, highly connected graphs. |