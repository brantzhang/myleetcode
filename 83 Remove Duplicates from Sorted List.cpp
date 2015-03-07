/*
Remove Duplicates from Sorted List 
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
	Given 1->1->2, return 1->2.
	Given 1->1->2->3->3, return 1->2->3
*/
//*************************************//

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
    ListNode *deleteDuplicates(ListNode *head) {
        if(head == NULL) return head;
        struct ListNode *p1 = new struct ListNode(0);
        struct ListNode *p2 = new struct ListNode(0);
        p1 = head;
        while(p1 && p1->next != NULL){
            if(p1->val == p1->next->val){
                p2 = p1->next;
                p1->next = p1->next->next;
                delete p2;
            } else {
                p1 = p1->next;
            }
        }
        return head;
    }
};