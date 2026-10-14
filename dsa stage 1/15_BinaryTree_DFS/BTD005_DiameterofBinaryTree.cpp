/*Date: 13th oct 2026
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