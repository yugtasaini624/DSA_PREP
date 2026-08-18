/*
Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.
The first node is considered odd, and the second node is even, and so on.
Note that the relative order inside both the even and odd groups should remain as it was in the input.
You must solve the problem in O(1) extra space complexity and O(n) time complexity.

Example 1:
Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]

Example 2:
Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]

Constraints:
    The number of nodes in the linked list is in the range [0, 104].
    -106 <= Node.val <= 106
*/

#include<iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr || head->next->next == nullptr){
            return head;
        }

        ListNode *odd_ptr = head;
        ListNode *even_ptr = odd_ptr->next;
        ListNode *curr = even_ptr->next;

        ListNode *odd_even_ptr = head->next;

        while(curr != nullptr){
            even_ptr->next = curr->next ? curr->next : nullptr;
            odd_ptr->next = curr;
            curr->next = odd_even_ptr;
            odd_ptr = odd_ptr->next;
            even_ptr = even_ptr->next;
            if(even_ptr){
                curr = even_ptr->next ? even_ptr->next : nullptr;
            } else{
                return head;
            }
        }

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

    head = obj.oddEvenList(head);
    ListNode* ptr = head;
    while(ptr != nullptr){
        cout<<ptr->val<<" ";
        ptr = ptr->next;
    }

    return 0;
}