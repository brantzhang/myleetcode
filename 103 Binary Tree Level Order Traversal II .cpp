/*
Binary Tree Level Order Traversal II 
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
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
 //非递归
class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > res;
        if(root==NULL){
            return res;
        }
        
        queue<TreeNode* > temp;
        TreeNode* pointer = root;
        temp.push(pointer);
        int level,counts;
        counts = 1;
        while(!temp.empty()){
            level = 0;
            vector<int> ttt;
            for(int i=0;i<counts;i++){
                pointer = temp.front();
                temp.pop();
                ttt.push_back(pointer->val);
                if(pointer->left != NULL){
                    temp.push(pointer->left);
                    level++;
                }
                if(pointer->right != NULL){
                    temp.push(pointer->right);
                    level++;
                }
            }
            res.insert(res.begin(),ttt);
            counts = level;
        }
        return res;
    }
};

//递归
class Solution
{
public:
    vector<vector<int> > result;

    void levelTra(TreeNode *root, int level)
    {
        if(root == NULL)
            return;
        if(level == result.size())
        {
            vector<int> v;
            result.push_back(v);
        }
        result[level].push_back(root->val);
        levelTra(root->left, level+1);
        levelTra(root->right, level+1);
    }

    vector<vector<int> > levelOrderBottom(TreeNode *root) 
    {
        levelTra(root, 0);
        return vector<vector<int> >(result.rbegin(), result.rend());
    }
};
