/*
Given the head of a singly linked list, reverse the list, and return the reversed list.

Example 1:
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Example 2:
Input: head = [1,2]
Output: [2,1]

Example 3:
Input: head = []
Output: []

Constraints:
    The number of nodes in the list is the range [0, 5000].
    -5000 <= Node.val <= 5000
*/

#include<iostream>
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
    ListNode* reverseList(ListNode* head) {
       if(head == nullptr || head->next == nullptr) return head;

       ListNode *ptr = head;
       ListNode *curr = ptr->next;
       ListNode *ptr2 = nullptr;

       head->next = nullptr;

       while(curr != nullptr){
        ptr2 = curr->next;
        curr->next = ptr;
        ptr = curr;
        curr = ptr2;
       } 

       head = ptr;
       return head;
    }
};

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next->next->next = new ListNode(8);

    Solution obj;

    head = obj.reverseList(head);
    ListNode* ptr = head;
    while(ptr != nullptr){
        cout<<ptr->val<<" ";
        ptr = ptr->next;
    }

    return 0;
}