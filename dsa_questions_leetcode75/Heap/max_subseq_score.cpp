/*
You are given two 0-indexed integer arrays nums1 and nums2 of equal length n and a positive integer k. You must choose a subsequence of indices from nums1 of length k.
For chosen indices i0, i1, ..., ik - 1, your score is defined as:

    The sum of the selected elements from nums1 multiplied with the minimum of the selected elements from nums2.
    It can defined simply as: (nums1[i0] + nums1[i1] +...+ nums1[ik - 1]) * min(nums2[i0] , nums2[i1], ... ,nums2[ik - 1]).

Return the maximum possible score.

A subsequence of indices of an array is a set that can be derived from the set {0, 1, ..., n-1} by deleting some or no elements.

 

Example 1:

Input: nums1 = [1,3,3,2], nums2 = [2,1,3,4], k = 3
Output: 12
Explanation: 
The four possible subsequence scores are:
- We choose the indices 0, 1, and 2 with score = (1+3+3) * min(2,1,3) = 7.
- We choose the indices 0, 1, and 3 with score = (1+3+2) * min(2,1,4) = 6. 
- We choose the indices 0, 2, and 3 with score = (1+3+2) * min(2,3,4) = 12. 
- We choose the indices 1, 2, and 3 with score = (3+3+2) * min(1,3,4) = 8.
Therefore, we return the max score, which is 12.

Example 2:

Input: nums1 = [4,2,3,1,1], nums2 = [7,5,10,9,6], k = 1
Output: 30
Explanation: 
Choosing index 2 is optimal: nums1[2] * nums2[2] = 3 * 10 = 30 is the maximum possible score.

 

Constraints:

    n == nums1.length == nums2.length
    1 <= n <= 105
    0 <= nums1[i], nums2[j] <= 105
    1 <= k <= n

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxScore(vector<int>& speed, vector<int>& efficiency, int k) {
        int n = speed.size();
        vector<pair<int, int>> ess(n);

        for (int i = 0; i < n; ++i)
            ess[i] = {efficiency[i], speed[i]};

        sort(ess.rbegin(), ess.rend());

        long long sumS = 0, res = 0;

        // Min heap
        priority_queue<int, vector<int>, greater<int> > pq;

        for (int i = 0; i < n; ++i) {
            int e = ess[i].first;
            int s = ess[i].second;

            pq.push(s);
            sumS += s;

            if (pq.size() > k) {
                sumS -= pq.top();
                pq.pop();
            }

            if (pq.size() == k) {
                res = max(res, sumS * e);
            }
        }

        return res;
    }
};

int main() {
    Solution obj;

    vector<int> speed = {2, 10, 3, 1, 5, 8};
    vector<int> efficiency = {5, 4, 3, 9, 7, 2};
    int k = 2;

    cout << obj.maxScore(speed, efficiency, k) << endl;

    return 0;
}
