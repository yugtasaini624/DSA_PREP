/*

*/

#include<iostream>
#include<vector>
using namespace std;

int longestSubarray(vector<int>& nums) {
    int n = nums.size();

    int len = 0, maxLen = len, zeros = 0, prev = 0;

    for(int i = 0;i < n;i++){
        if(nums[i] == 0) zeros++;

        while(zeros > 1){
            if(nums[prev] == 0){
                zeros--;
            }
            prev++;
        }

        len = i - prev + 1;
        maxLen = max(maxLen, len - 1);
    }
    return maxLen;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0;i < n;i++){
        cin>>arr[i];
    }

    cout<<longestSubarray(arr);
}