/*
199 Binary Tree Right Side View 
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].
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
    vector<int> rightSideView(TreeNode *root) {
        queue<TreeNode*> nodeQ;  //节点队列
        vector<int> res;
        if(root == NULL){
            return res;
        }
        TreeNode* pointer = root;
        nodeQ.push(pointer);
        int level = 1;
        int counts = 0;
        while(!nodeQ.empty()){
            counts = 0;
            for(int i=0;i<level;i++){
                pointer = nodeQ.front();
                nodeQ.pop();
                if(pointer->left!=NULL){
                    nodeQ.push(pointer->left);
                    counts++;
                }
                if(pointer->right!=NULL){
                    nodeQ.push(pointer->right);
                    counts++;
                }
            }
            res.push_back(pointer->val);
            level = counts;
        }
    }
};