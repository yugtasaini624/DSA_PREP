/*
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Note that you must do this in-place without making a copy of the array.

Example 1:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

Example 2:
Input: nums = [0]
Output: [0]

Constraints:
    1 <= nums.length <= 104
    -231 <= nums[i] <= 231 - 1
*/

#include<iostream>
#include<vector>
using namespace std;

void moveZeroes(vector<int>& arr) {
    int n = arr.size();

    int i = 0, j = 0;

    while(i < n && j < n){
        while(j < n && arr[j] == 0){
            j++;
        }

        if(j >= n) break;

        swap(arr[i], arr[j]);
        i++;
        j++;
    }

    return;
}

int main(){
    int n;
    cout<<"Enter the size: ";
    cin>>n;

    vector<int> arr(n);

    cout<<"Enter elements in array: ";
    for(int i = 0;i < n;i++){
        cin>>arr[i];
    }

    moveZeroes(arr);

    cout<<"New Array: ";
    for(int i = 0;i < n;i++)
        cout<<arr[i]<<" ";

    return 0;
}