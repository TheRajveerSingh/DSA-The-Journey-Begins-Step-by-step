/**
 * PROBLEM NAME: Nim Game (LeetCode 292)
 * 
 * DESCRIPTION:
 * You are playing the Nim Game with a friend. 
 * There is a heap of stones on the table. You and your friend take turns.
 * You always go first. On each turn, a player can remove 1 to 3 stones.
 * The player who removes the last stone wins the game.
 * 
 * SAMPLE INPUT & OUTPUT:
 * - Input: n = 4   => Output: false (0) -> You take 1, 2, or 3, friend takes the rest and wins.
 * - Input: n = 1   => Output: true (1)  -> You take 1 stone and win immediately.
 * - Input: n = 2   => Output: true (1)  -> You take 2 stones and win immediately.
 * - Input: n = 5   => Output: true (1)  -> You take 1 stone (4 left), friend is guaranteed to lose.
 * 
 * STRATEGY:
 * - If the number of stones (n) is a multiple of 4, you will always lose.
 * - No matter if you pick 1, 2, or 3 stones, your opponent can pick the complement (3, 2, or 1) 
 *   to keep the remaining stones a multiple of 4.
 * - Therefore, if n % 4 == 0, return 0 (false). Otherwise, return 1 (true).
 * - Time Complexity: O(1)
 * - Space Complexity: O(1)
 */

#include <iostream>
using namespace std;

class Solution {
public:
    bool canWinNim(int n) {
        if (n % 4 == 0)
            return 0;
        else
            return 1;
    }
};

int main() {
    Solution solver;
    int stones;

    cout << "Enter the number of stones in the heap: ";
    cin >> stones;

    if (stones <= 0) {
        cout << "Please enter a valid number of stones greater than 0." << endl;
        return 0;
    }

    if (solver.canWinNim(stones)) {
        cout << "Result: You can win the game!" << endl;
    } else {
        cout << "Result: You will lose the game." << endl;
    }

    return 0;
}
