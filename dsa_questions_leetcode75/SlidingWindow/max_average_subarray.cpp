/*
You are given an integer array nums consisting of n elements, and an integer k. Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.

Example 1:
Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75

Example 2:
Input: nums = [5], k = 1
Output: 5.00000

Constraints:
    n == nums.length
    1 <= k <= n <= 105
    -104 <= nums[i] <= 104
*/

#include<iostream>
#include<vector>
using namespace std;

double findMaxAverage(vector<int>& nums, int k) {
    int n = nums.size();

    int sum = 0;

    for(int i = 0;i < k;i++){
        sum += nums[i];
    }

    int j = 0, maxSum = sum;

    for(int i = k;i < n;i++){
        sum = sum - nums[j] + nums[i];
        maxSum = max(sum, maxSum);
        j++;
    }

    return (double) maxSum / k;
}

int main(){
    int n, k;
    cout<<"Enter the size and window size: ";
    cin>>n>>k;

    vector<int> arr(n);

    cout<<"Enter elements: ";
    for(int i = 0;i < n;i++){
        cin>>arr[i];
    }

    cout<<findMaxAverage(arr, k);
    return 0; 
}