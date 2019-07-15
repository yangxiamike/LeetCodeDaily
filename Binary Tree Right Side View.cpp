//
//  Binary Tree Right Side View.cpp
//  Leetcode
//
//  Created by xiayang on 2019/7/14.
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
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        int depth = 0, curr_depth = 0;
        vector<int> path;
        pathadd(root, depth, curr_depth + 1, path);
        return path;
    }
    
    void pathadd(TreeNode* node, int& depth, int curr_depth,
                 vector<int>& path){
        if (node == nullptr)
            return ;
        if (curr_depth > depth){
            path.push_back(node -> val);
            depth += 1;
        }
        pathadd(node -> right, depth, curr_depth + 1, path);
        pathadd(node -> left, depth, curr_depth + 1, path);
    }
};
