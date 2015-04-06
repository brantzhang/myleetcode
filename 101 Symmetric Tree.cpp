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
    bool isSymmetric(TreeNode *root) {
        if(root==NULL) return true;
        if(root->left==NULL&&root->right==NULL){return true;}
        queue<TreeNode* > leftTree;
        queue<TreeNode* > rightTree;
        if(root->left!=NULL&&root->right!=NULL){
            TreeNode* leftPoint = root->left;
            TreeNode* rightPoint = root->right;
            leftTree.push(leftPoint);
            rightTree.push(rightPoint);
            while((!leftTree.empty())&&(!rightTree.empty())){
                leftPoint = leftTree.front();
                leftTree.pop();
                rightPoint = rightTree.front();
                rightTree.pop();
                if(leftPoint==NULL||rightPoint==NULL){
                    if(leftPoint==NULL&&rightPoint==NULL){
                        continue;
                    }else{
                        return false;
                    }
                }
                if(leftPoint->val!=rightPoint->val) return false;
                leftTree.push(leftPoint->left);
                leftTree.push(leftPoint->right);
                rightTree.push(rightPoint->right);
                rightTree.push(rightPoint->left);
            }
            return true;
        }
        return false;
    }
};