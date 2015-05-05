/*
Sort List
Sort a linked list in O(n log n) time using constant space complexity.
*/

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
    
    ListNode* merge(ListNode* p1,ListNode* p2){//�ϲ�p1��p2��������������
        ListNode* head;
        ListNode* p;
        if(p1->val<p2->val){
            p = head = p1;
            p1 = p1->next;
        }else{
            p = head = p2;
            p2 = p2->next;
        }
        while(p1&&p2){
            if(p1->val<=p2->val){
                p->next = p1;
                p1 = p1->next;
                p = p->next;
            }else{
                p->next = p2;
                p2 = p2->next;
                p = p->next;
            }
        }
        if(p1){
            p->next = p1;
        }else{
            p->next = p2;
        }
        return head;
    }
    
    ListNode* dfs(ListNode* head){
        if(!head||!head->next){  //û��Ԫ�ػ���ֻ��һ��Ԫ��
            return head;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* mid;
        while(fast&&fast->next){
            fast= fast->next->next;
            mid = slow;
            slow = slow->next;
        }
        mid->next = NULL;//�ֳ���������
        
        return merge(dfs(head),dfs(slow));
    }
    
    ListNode* sortList(ListNode* head) {
        if(!head||!head->next){
            return head;
        }
        return dfs(head);
    }
};