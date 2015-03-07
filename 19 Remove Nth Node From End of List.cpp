/*
Remove Nth Node From End of List 
Given a linked list, remove the nth node from the end of list and return its head.

For example,
   Given linked list: 1->2->3->4->5, and n = 2.
   After removing the second node from the end, the linked list becomes 1->2->3->5.
   
Note:
Given n will always be valid.
Try to do this in one pass.
*/

//1st solution
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        int nums=0;
        struct ListNode *p = new struct ListNode(0);
        p = head;
        if(p != NULL) nums++;
        while(p->next != NULL){
            nums++;
            p = p->next;
        }
        
        p = head;
        if(nums==n){
            return head->next;
        }
        for(int i=1;i<nums-n;i++){
            p = p->next;
        }
        p->next = p->next->next;
        
        return head;
    }
};

//2nd solution
//使用两个指针，两个指针之间间隔n-1个位置，那么当后一个指针到达链表最后时，前一个指针的next就是要删除的指针
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        int nums=0;
        struct ListNode *p1 = new struct ListNode(0);
        struct ListNode *p2 = new struct ListNode(0);
        p1 = p2 = head;
        for(int i=0;i<n;i++){
            p2 = p2->next;
        }
        if(p2 == NULL) return head->next;
        while(p2->next != NULL){
            p1 = p1->next;
            p2 = p2->next;
        }
        
        p1->next = p1->next->next;
        return head;
    }
};