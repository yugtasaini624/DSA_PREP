/*
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.Merge nums1 and nums2 into a single array sorted in non-decreasing order.The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

Example 1:
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

Example 2:
Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].

Example 3:
Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.

Constraints:
    nums1.length == m + n
    nums2.length == n
    0 <= m, n <= 200
    1 <= m + n <= 200
    -109 <= nums1[i], nums2[j] <= 109
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int idx = m + n - 1;
    int i = m - 1, j = n - 1;

    while(idx >= 0){
        int val1 = i >= 0 ? nums1[i] : INT_MIN;
        int val2 = j >= 0 ? nums2[j] : INT_MIN;

        nums1[idx] = max(val1, val2);
        if(nums1[idx] == val1) i--;
        else j--;

        idx--;
    }

} 


int main(){
    int n, m;
    cout<<"Enter two size: ";
    cin>>m>>m;

    vector<int> arr1(m+n, 0);
    vector<int> arr2;

    cout<<"Enter elements for array 1: ";
    for(int i = 0;i < m;i++){
        cin>>arr1[i];
    }

    cout<<"Enter elements for array 2: ";
    for(int i = 0;i < n;i++){
        cin>>arr2[i];
    }

    merge(arr1, m, arr2, n);

    cout<<"Merged array: ";
    for(int i = 0;i < m + n;i++){
        cout<<arr1[i]<<" ";
    }

    return 0;
}