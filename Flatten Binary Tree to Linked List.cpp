//
//  Flatten Binary Tree to Linked List.cpp
//  Leetcode
//
//  Created by xiayang on 2019/7/16.
//  Copyright © 2019 xiayang. All rights reserved.
//

#include <stdio.h>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//O(N) DFS - recursion, large memory
class Solution {
public:
    void flatten(TreeNode* root) {
        vector<TreeNode*> path;
        if (root == nullptr)
            return;
        dfs(path, root);
        for (int i = 0; i < path.size() - 1; i++){
            path[i]->left = nullptr;
            path[i]->right = path[i + 1];
        }
        path[path.size() -1]->right = nullptr;
    }
    void dfs(vector<TreeNode*>& path, TreeNode* node){
        path.push_back(node);
        if (node->left != nullptr)
            dfs(path, node->left);
        if (node->right != nullptr)
            dfs(path, node->right);
    }
};


//ON(N) DFS , O(1) memory
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while (curr){
            if (curr->left){
                TreeNode* temp = curr->left;
                while (temp->right) temp = temp->right;
                temp->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
            }
            curr = curr->right;
        }
    }
};
