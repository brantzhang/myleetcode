/*Path Sum II 
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
***************************/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //Solution-1 我自己写的，还是根据先序遍历
class Solution {
public:
    vector<vector<int> > result;
    void preOrder(TreeNode* root,int num,int sum,vector<int> temp){
        if(root==NULL){return;}
        num = num+root->val;
        temp.push_back(root->val);
        if(root->left==NULL&&root->right==NULL){
            if(num==sum)  result.push_back(temp);
        }
        preOrder(root->left,num,sum,temp);
        preOrder(root->right,num,sum,temp);
    }
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<int> vvv;
        preOrder(root,0,sum,vvv);
        return result;
    }
};
