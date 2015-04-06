/*
100 Same Treee
Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//我写的
class Solution {
public:
    bool preOrder(TreeNode* root1,TreeNode* root2){
        if(root1==NULL||root2==NULL){
            if(root1!=root2) return false;
        }
        if(root1!=NULL&&root2!=NULL){
            if(root1->val!=root2->val){
                return false;
            }
            return preOrder(root1->left,root2->left)&&preOrder(root1->right,root2->right);
        }
        return true;
    }
    
    bool midOrder(TreeNode* root1,TreeNode* root2){
        if(root1==NULL||root2==NULL){
            if(root1!=root2) return false;
        }
        if(root1!=NULL&&root2!=NULL){
            if(!midOrder(root1->left,root2->left)) return false;
            if(root1->val != root2->val) return false;
            if(!midOrder(root1->right,root2->right)) return false;
        }
        return true;
    }
    
    bool isSameTree(TreeNode *p, TreeNode *q) {
        return preOrder(p,q)&&midOrder(p,q);
    }
};


//别人的写的直接递归：
class Solution {  
public:  
    bool isSameTree(TreeNode *p, TreeNode *q) {  
        // Start typing your C/C++ solution below  
        // DO NOT write int main() function  
        if (p == NULL && q == NULL)  
            return true;  
        else if (p == NULL || q == NULL)  
            return false;  
        return p->val == q->val && isSameTree(p->left, q->left)  
            && isSameTree(p->right, q->right);  
    }  
};  