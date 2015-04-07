/*Binary Tree Maximum Path Sum 
Given a binary tree, find the maximum path sum.
The path may start and end at any node in the tree.
For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.
************************/
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
    int result;
    int scanT(TreeNode* root){//���ص���������Ӹ��ڵ㿪ʼֻ��������һ����ʱ������������ʾ�����ֵ�����ֵ��·�������ֵ�ǲ�һ����
        if(root == NULL) return 0;
        int left = scanT(root -> left);
        int right = scanT(root -> right);
        int value = root -> val;
        if(left > 0) value += left;
        if(right > 0) value += right;
        if(value > result) result = value;
        return max(root->val ,max(left +  root -> val , right + root -> val));
    }
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL) return 0;
        result = root -> val;
        scanT(root);
        return result;
    }
};
