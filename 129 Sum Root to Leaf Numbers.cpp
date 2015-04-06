/*
Sum Root to Leaf Numbers
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
An example is the root-to-leaf path 1->2->3 which represents the number 123.
Find the total sum of all root-to-leaf numbers.
For example,
    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Return the sum = 12 + 13 = 25.
*///**************************************

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sum;
    void preSum(TreeNode* root,int num){//可以看做是一个先序遍历的过程
        num = num*10+root->val;
        if(root->left==NULL&&root->right==NULL){
            sum += num;
        }
        if(root->left!=NULL){
            preSum(root->left,num);
        }
        if(root->right!=NULL){
            preSum(root->right,num);
        }
    }

    int sumNumbers(TreeNode *root) {
        if(root==NULL) return 0;
        sum=0;
        preSum(root,0);
        return sum;
    }
};

