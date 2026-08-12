/*
Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.

Example 1:
Input: nums = [1,2,3,4,5]
Output: true
Explanation: Any triplet where i < j < k is valid.

Example 2:
Input: nums = [5,4,3,2,1]
Output: false
Explanation: No triplet exists.

Example 3:
Input: nums = [2,1,5,0,4,6]
Output: true
Explanation: One of the valid triplet is (1, 4, 5), because nums[1] == 1 < nums[4] == 4 < nums[5] == 6.

Constraints:
    1 <= nums.length <= 5 * 105
    -231 <= nums[i] <= 231 - 1
Follow up: Could you implement a solution that runs in O(n) time complexity and O(1) space complexity?
*/

#include<iostream>
#include<vector>
using namespace std;

bool increasingTriplet(vector<int>& nums) {
    int firstNum = INT_MAX, secNum = INT_MAX;

    for(int i = 0;i < nums.size();i++){
        if(nums[i] <= firstNum) firstNum = nums[i];
        else if(nums[i] <= secNum) secNum = nums[i];
        else return true;
    }

    return false;
}

int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;

    cout<<"Enter elements: ";
    vector<int> arr(n);
    for(int i = 0;i < n;i++){
        cin>>arr[i];
    }
    
    cout<<"Does a seq exist or not = >  "<<increasingTriplet(arr);
    return 0;
}