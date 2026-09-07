/*
The Tribonacci sequence Tn is defined as follows: 
T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.
Given n, return the value of Tn.

Example 1:

Input: n = 4
Output: 4
Explanation:
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4

Example 2:

Input: n = 25
Output: 1389537

 

Constraints:

    0 <= n <= 37
    The answer is guaranteed to fit within a 32-bit integer, ie. answer <= 2^31 - 1.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rec(int n, vector<int> &dp){
        if(dp[n] != -1) return dp[n];

        return dp[n] = rec(n - 1, dp) + rec(n - 2, dp) + rec(n - 3, dp);
    }

    int tribonacci(int n) {
        vector<int> dp(n + 1, -1);

        dp[0] = 0;

        if (n >= 1) dp[1] = 1;

        if (n >= 2) dp[2] = 1;

        if (n >= 3) dp[3] = 2;

        return rec(n, dp);
    }
};

int main() {
    int n;
    cin >> n;

    Solution obj;

    cout << obj.tribonacci(n);

    return 0;
}
