/*
Given an array of positive integers nums and a positive integer target, return the minimal length of a whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

Example 1:
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.

Example 2:
Input: target = 4, nums = [1,4,4]
Output: 1

Example 3:
Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0

Constraints:
    1 <= target <= 109
    1 <= nums.length <= 105
    1 <= nums[i] <= 104
*/

#include<iostream>
#include<vector>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();

    int minLen = INT_MAX;

    int i = 0;
    int currSum = 0;
    for(int j = 0;j < n;j++){
        if(nums[j] >= target) minLen = 1;

        currSum += nums[j];

        while(i < j && currSum >= target){
            minLen = min(minLen, j - i + 1);
            currSum -= nums[i];
            i++;
        }
    }
    return minLen == INT_MAX ? 0 : minLen;
}

int main(){
    int n, target;
    cout<<"Enter the size: ";
    cin>>n>>target;

    vector<int> arr(n);
    cout<<"Enter the elements: ";
    for(int i = 0;i < n;i++){
        cin>>arr[i];
    }

    cout<<"Min len = "<<minSubArrayLen(target, arr);
}