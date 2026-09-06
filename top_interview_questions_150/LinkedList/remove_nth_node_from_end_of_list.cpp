/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:

Input: head = [1], n = 1
Output: []

Example 3:

Input: head = [1,2], n = 1
Output: [1]

 

Constraints:

    The number of nodes in the list is sz.
    1 <= sz <= 30
    0 <= Node.val <= 100
    1 <= n <= sz

*/

#include<bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* start, int n) {
        int count = 0;

        ListNode *ptr = start;
        while(ptr != nullptr){
            count++;
            ptr = ptr->next;
        }

        int pos = count - n + 1;

        if(pos == 1){
            start = start->next;
            return start;
        }

        int currPos = 1;
        ListNode *prev = start;
        ptr = start;
        while(ptr != nullptr && currPos != pos){
            prev = ptr;
            ptr = ptr->next;
            currPos++;
        }

        prev->next = ptr->next;
        ptr->next = nullptr;
        delete ptr;

        return start;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 2;

    Solution obj;
    head = obj.removeNthFromEnd(head, n);

    ListNode* temp = head;

    while(temp != nullptr) {
        cout << temp->val;

        if(temp->next != nullptr)
            cout << " -> ";

        temp = temp->next;
    }

    cout << endl;

    return 0;
}
