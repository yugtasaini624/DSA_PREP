/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

Example 3:

Input: nums = [1,0,1,2]
Output: 3

Constraints:

    0 <= nums.length <= 105
    -109 <= nums[i] <= 109

*/

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxLen = 0;
        unordered_set<int> s(nums.begin(), nums.end());

        for(int num: s){
            if(s.find(num - 1) == s.end()){
                int len = 1;
                int curr = num;

                while(s.find(curr + 1) != s.end()){
                    curr++;
                    len++;
                }

                maxLen = max(len, maxLen);
            }
        }
        return maxLen;
    }
};

int main(){
    Solution sol;
    int n;
    cin>>n;

    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    } 
    cout<<sol.longestConsecutive(nums);
    return 0;
}