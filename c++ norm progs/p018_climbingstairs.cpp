/*This is a question from leetcode which I just practiced because it looked interesting.
Here was the Question:
Question 70. Climbing Stairs.
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:
Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 
Constraints:
1 <= n <= 45
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        // We track the number of ways for the previous two steps
        int prev2 = 1;
        int prev1 = 2;
        int current = 0;
        // Now, iteratively calculate ways for remaining steps up to n
        for (int i = 3; i <= n; i++) {
            current = prev1 + prev2;
            prev2 = prev1;   // Moves pointer forward
            prev1 = current; // Moves pointer forward
        }
        
        return prev1;
    }
};

int main() {
    Solution solver;
    int n;
    
    cout << "Enter the number of steps: ";
    if (cin >> n) {
        // We ensure that input is valid based on LeetCode constraints
        if (n < 1 || n > 45) {
            cout << "Please enter a number between 1 and 45." << endl;
            return 1;
        }
        
        int result = solver.climbStairs(n);
        cout << "Number of distinct ways to climb to the top: " << result << endl;
    }
    
    return 0;
}


/*
Let's say that we are standing on Step 4.Now, because we can only jump 1 step or 2 steps 
at a time, there are only two possible places we could have jumped from to get to Step 4:
We were on Step 3 and took a 1-step jump. Or;
We were on Step 2 and took a 2-step jump.
This means the total number of ways to reach Step 4 is simply:
(Ways to reach Step 3)+(Ways to reach Step 2)
So, like, if we observe, step-by-step:
Step 1: Only 1 way → [1]
Step 2: 2 ways → [1+1] or [2]
Step 3: (Ways to Step 2) + (Ways to Step 1) → 2 + 1 = 3 ways
Step 4: (Ways to Step 3) + (Ways to Step 2) → 3 + 2 = 5 ways
Step 5: (Ways to Step 4) + (Ways to Step 3) → 5 + 3 = 8 ways
So, the code uses this:
Instead of recalculating everything from scratch, the code just remembers 
the last two numbers in this pattern and adds them together to get the next number, 
exactly like the Fibonacci sequence.
*/