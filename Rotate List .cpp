/*
Rotate List 
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
*/
//****************************//

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
    ListNode *rotateRight(ListNode *head, int k) {
        struct ListNode *p1 = new struct ListNode(0);
        struct ListNode *p2 = new struct ListNode(0);
        struct ListNode *p3 = new struct ListNode(0);
        p3 = p2 = p1 = head;
        if(head == NULL) return head;
        int n=0;
        while(p1 != NULL){
            n++;
            p1 = p1->next;
        }
        k = k%n;
        if(k==0) return head;
        p1 = head;
        
        for(int i=0;i<k-1;i++){
            if(p2 != NULL){
                p2 = p2->next;
            }
        }
        if(p2 == NULL) return head;
        if(p2->next != NULL){
            p1 = p1->next;
            p2 = p2->next;
        }
        while(p2->next != NULL){
            p1 = p1->next;
            p2 = p2->next;
            p3 = p3->next;
        }
        p2->next = head;
        p3->next = NULL;
        head = p1;
        return head;
    }
};

