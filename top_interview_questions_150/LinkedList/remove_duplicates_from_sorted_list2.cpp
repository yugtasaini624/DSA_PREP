/*
You are given the head of a sorted linked list.
Delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
Return the linked list sorted as well.

Example 1:

Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]

Example 2:

Input: head = [1,1,1,2,3]
Output: [2,3]

 

Constraints:

    The number of nodes in the list is in the range [0, 300].
    -100 <= Node.val <= 100
    The list is guaranteed to be sorted in ascending order.

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        ListNode *tail = dummy;

        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode *ptr = head->next;
        ListNode *prev = head;
        int val = INT_MAX;

        while(ptr != NULL){
            if(ptr->val != prev->val){
                if(prev->val != val){
                    ListNode *newNode = new ListNode(prev->val);
                    tail->next = newNode;
                    tail = tail->next;
                    prev = ptr;
                    ptr = ptr->next;
                } else {
                    prev = ptr;
                    ptr = ptr->next;
                }
            } else {
                val = prev->val;
                prev = ptr;
                ptr = ptr->next;
            }
        }
        if(prev->next == NULL && prev->val != val){
            ListNode *newNode = new ListNode(prev->val);
            tail->next = newNode;
            tail = tail->next;
        }
        return dummy->next;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);
    head->next->next->next->next->next = new ListNode(4);

    Solution obj;

    ListNode* ans = obj.deleteDuplicates(head);
    ListNode* temp = ans;

    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }

    return 0;
}
