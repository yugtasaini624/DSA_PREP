/*
You have a set which contains all positive integers [1, 2, 3, 4, 5, ...].

Implement the SmallestInfiniteSet class:

    SmallestInfiniteSet() Initializes the SmallestInfiniteSet object to contain all positive integers.
    int popSmallest() Removes and returns the smallest integer contained in the infinite set.
    void addBack(int num) Adds a positive integer num back into the infinite set, if it is not already in the infinite set.

 

Example 1:

Input
["SmallestInfiniteSet", "addBack", "popSmallest", "popSmallest", "popSmallest", "addBack", "popSmallest", "popSmallest", "popSmallest"]
[[], [2], [], [], [], [1], [], [], []]
Output
[null, null, 1, 2, 3, null, 1, 4, 5]

Explanation
SmallestInfiniteSet smallestInfiniteSet = new SmallestInfiniteSet();
smallestInfiniteSet.addBack(2);    // 2 is already in the set, so no change is made.
smallestInfiniteSet.popSmallest(); // return 1, since 1 is the smallest number, and remove it from the set.
smallestInfiniteSet.popSmallest(); // return 2, and remove it from the set.
smallestInfiniteSet.popSmallest(); // return 3, and remove it from the set.
smallestInfiniteSet.addBack(1);    // 1 is added back to the set.
smallestInfiniteSet.popSmallest(); // return 1, since 1 was added back to the set and
                                   // is the smallest number, and remove it from the set.
smallestInfiniteSet.popSmallest(); // return 4, and remove it from the set.
smallestInfiniteSet.popSmallest(); // return 5, and remove it from the set.

 

Constraints:

    1 <= num <= 1000
    At most 1000 calls will be made in total to popSmallest and addBack.

*/

#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>
using namespace std;

class SmallestInfiniteSet {
public:
    int current;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    unordered_set<int> addedBack;

    SmallestInfiniteSet() {
        current = 1;
    }

    int popSmallest() {
        if (!minHeap.empty()) {
            int smallest = minHeap.top();   
            minHeap.pop();
            addedBack.erase(smallest);      
            return smallest;
        }
        return current++;
    }

    void addBack(int num) {
        if (num < current && addedBack.find(num) == addedBack.end()) {
            minHeap.push(num);       
            addedBack.insert(num);   
        }
    }
};

int main() {
    SmallestInfiniteSet obj;

    cout<<obj.popSmallest()<<endl; 
    cout<<obj.popSmallest()<<endl; 

    obj.addBack(1);

    cout<<obj.popSmallest()<<endl;
    cout<<obj.popSmallest()<<endl;

    obj.addBack(2);

    cout<<obj.popSmallest()<<endl; 
    cout<<obj.popSmallest()<<endl; 

    return 0;
}