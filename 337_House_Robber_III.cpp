/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int rob(TreeNode* root) {
        if(root == nullptr) return 0;

        int take = root->val;

        if(root->left) {
            take += rob(root->left->left);
            take += rob(root->left->right);
        }

        if(root->right) {
            take += rob(root->right->left);
            take += rob(root->right->right);
        }

        int skip = rob(root->left) + rob(root->right);

        return max(take, skip);
    }
};