/*
Swap Nodes in Pairs

Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*//**************************************************

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if(head == NULL || head->next == NULL) return head;
        struct ListNode *p = new struct ListNode(0);
        struct ListNode *temp1 = new struct ListNode(0);
        struct ListNode *temp2 = new struct ListNode(0);
        
        temp1 = head;
        temp2 = head->next; 
        temp1->next = temp2->next;
        temp2 ->next = temp1;
        head = temp2;
        
        p = temp1;
        while(p!=NULL){
            if(p->next != NULL) temp1 = p->next;
            else return head;
            if(temp1->next != NULL) temp2 = temp1->next;
            else return head;
            p->next = temp2;
            temp1->next = temp2->next;
            temp2->next = temp1;
            p = p->next->next;
        }
        return head;
    }
};