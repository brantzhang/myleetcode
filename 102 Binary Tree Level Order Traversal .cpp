/*
Binary Tree Level Order Traversal 
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
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
class Solution {
public:
    
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector< vector<int> > res;
        if(root==NULL){
            return res;
        }
        queue<TreeNode*> temp;
        TreeNode *pointer = root;
        temp.push(pointer);
        int level=0;
        int counts=0;
        counts++;
        while(!temp.empty()){
            level = 0;
           vector<int > tt;
           for(int i=0;i<counts;i++){
               pointer = temp.front();
               temp.pop();
               tt.push_back(pointer->val);
               if(pointer->left!=NULL){
                  temp.push(pointer->left);
                  level++;
                }
                if(pointer->right!=NULL){
                    temp.push(pointer->right);
                    level++;
                }
           }
           counts = level;
           res.push_back(tt);
        }
        return res;
    }
};