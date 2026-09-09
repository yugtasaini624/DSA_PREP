/*
You have two types of tiles: a 2 x 1 domino shape and a tromino shape. You may rotate these shapes.

Given an integer n, return the number of ways to tile an 2 x n board. Since the answer may be very large, return it modulo 109 + 7.

In a tiling, every square must be covered by a tile. Two tilings are different if and only if there are two 4-directionally adjacent cells on the board such that exactly one of the tilings has both squares occupied by a tile.

 

Example 1:

Input: n = 3
Output: 5
Explanation: The five different ways are shown above.

Example 2:

Input: n = 1
Output: 1

 

Constraints:

    1 <= n <= 1000

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        const long mod = 1e9 + 7;
        long dominoes(int i, int n, bool possible) {
            if (i == n) return !possible;
            if (i > n) return 0;
            if (possible)
                return (dominoes(i + 1, n, false) + 
                        dominoes(i + 1, n, true)) % mod;
            return (dominoes(i + 1, n, false) + 
                    dominoes(i + 2, n, false) + 
                    2L * dominoes(i + 2, n, true)) % mod;
            }

        int numTilings(int n) {
            return dominoes(0, n, false);
        }
};

int main() {
    int n;
    cin >> n;

    Solution obj;
    cout << obj.numTilings(n) << endl;

    return 0;
}