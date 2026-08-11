/*
You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.

Example 1:
Input: flowerbed = [1,0,0,0,1], n = 1
Output: true

Example 2:
Input: flowerbed = [1,0,0,0,1], n = 2
Output: false

Constraints:
    1 <= flowerbed.length <= 2 * 104
    flowerbed[i] is 0 or 1.
    There are no two adjacent flowers in flowerbed.
    0 <= n <= flowerbed.length
*/

#include<iostream>
#include<vector>
using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    if(n == 0) return true;
        
    int size = flowerbed.size();

    for(int i = 0;i < size;i++){
        int left = (i == 0) ? 0 : flowerbed[i - 1];
        int right = (i == size - 1) ? 0 : flowerbed[i + 1];

        if(left == 0 && right == 0 && flowerbed[i] == 0){
            flowerbed[i] = 1;
            n--;
        }

        if(n == 0) break;
    }

    return (n == 0) ? true : false;
}

int main(){
    int size, n;
    cout<<"Enter size of array and no of plants: ";
    cin>>size>>n;

    cout<<"Enter elements: ";
    vector<int> arr(size);
    for(int i = 0;i < size;i++){
        cin>>arr[i];
    }
    
    cout<<"Can we plant all flowers???? = >  "<<canPlaceFlowers(arr, n);
    return 0;
}