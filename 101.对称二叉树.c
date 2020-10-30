/*
 * @lc app=leetcode.cn id=101 lang=c
 *
 * [101] 对称二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isSymmetric(struct TreeNode* root){

    if(!root)
        return true;
    else if(root->left |&& root->right) {

    } else if(!root->left && !root->right)
        return true;
    else
        return false;
}


// @lc code=end

