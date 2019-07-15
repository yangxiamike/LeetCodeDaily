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
    int sumNumbers(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int curr = 0, sum = 0;
        sumpath(root, curr, sum);
        return sum;
    }
    void sumpath(TreeNode* node, int curr, int& sum){
        curr = curr * 10 + node -> val;
        if (node -> left == nullptr && node -> right == nullptr){
            sum += curr;
        }
        if (node -> left != nullptr)
            sumpath(node -> left, curr, sum);
        if (node -> right != nullptr)
            sumpath(node -> right, curr, sum);
    }
};/
