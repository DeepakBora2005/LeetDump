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
    int ans = INT_MIN;
    int find(TreeNode *root) {
        if(root == nullptr) return 0;

        int left = find(root->left);
        int right = find(root->right);

        int temp = root->val;
        temp = max(temp, root->val + left + right);

        ans = max(ans, temp);

        return root->val + left + right;
    }

    int maxPathSum(TreeNode* root) {
        find(root);

        return ans;
    }
};