/*
Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

 

Example 1:

Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]

Example 2:

Input: head = [2,1], x = 2
Output: [1,2]

 

Constraints:

    The number of nodes in the list is in the range [0, 200].
    -100 <= Node.val <= 100
    -200 <= x <= 200

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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy = new ListNode(0) ;
        dummy -> next = head ; 

        ListNode* temp1 = dummy ; 

        while(temp1 -> next != nullptr && temp1 -> next -> val < x){
            temp1 = temp1 -> next ; 
        }

        ListNode* temp2 = temp1 ; 

        while(temp2 != nullptr && temp2 -> next != nullptr){
            ListNode* temp = temp2 -> next;

            if(temp2 -> next -> val < x){                
                temp2 -> next = temp -> next;
                temp -> next = temp1 -> next;
                temp1 -> next = temp;
                
                temp1 = temp; 
            }
            else {
                temp2 = temp2 -> next ; 
            }
        }

        ListNode* newHead = dummy -> next;
        delete dummy;
        return newHead ;
    }
};

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(2);

    int x = 3;

    cout << "Original list: ";
    printList(head);

    Solution obj;
    head = obj.partition(head, x);

    cout << "After partition: ";
    printList(head);

    return 0;
}