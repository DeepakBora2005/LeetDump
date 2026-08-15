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
    int find(TreeNode *root) {
        if(root == nullptr) return 0;


        int left = 1 + find(root->left);
        int right = 1 + find(root->right);

        return (left - right);
    }

    bool isBalanced(TreeNode* root) {
        int ans = find(root);

        return ans <= 1;
    }
};