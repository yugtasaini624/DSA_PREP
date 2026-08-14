/*
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

Example 1:
Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

Example 2:
Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

Constraints:
    1 <= nums.length <= 105
    nums[i] is either 0 or 1.
    0 <= k <= nums.length
*/

#include<iostream>
#include<vector>
using namespace std;

int longestOnes(vector<int>& nums, int k) {
    int n = nums.size();

    int len = 0, zeros = 0;
    int maxLen = len;

    int prev = 0;
    for(int i = 0;i < n;i++){
        if(nums[i] == 1 || zeros < k){
            len++;
            maxLen = max(len, maxLen);
            if(nums[i] == 0) zeros++;
        } else{
            while(nums[prev] != 0){
                len--;
                prev++;
            }
            prev++;
            maxLen = max(maxLen, len);
        }
    }
    return maxLen;
}

int main(){
    int n, k;
    cout<<"Enter size and no of flips: ";
    cin>>n>>k;  

    vector<int> arr(n);

    cout<<"Enter elements: ";
    for(int i = 0;i < n;i++){
        cin>>arr[i];
    }

    cout<<"Max Len = "<<longestOnes(arr, k);
}