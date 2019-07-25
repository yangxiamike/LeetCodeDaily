//
//  Insufficient Nodes in Root to Leaf Paths Insufficient Nodes in Root to Leaf Paths Insufficient Nodes in Root to Leaf Paths Insufficient Nodes in Root to Leaf Paths.cpp
//  Leetcode
//
//  Created by xiayang on 2019/7/25.
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
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        return checklimit(root, limit, 0);
        
    }
    
    TreeNode* checklimit(TreeNode* node, int limit, int sum){
        if (node == nullptr)
            return nullptr;
        
        if (node -> left == nullptr && node -> right == nullptr){
            if ((sum + node -> val) >= limit)
                return node;
            else return nullptr;
        }
        
        node -> left = checklimit(node -> left, limit, sum + node -> val);
        node -> right = checklimit(node -> right, limit, sum + node -> val);
        
        if (!node -> left && !node -> right)
            return nullptr;
        
        return node;
    }
};
