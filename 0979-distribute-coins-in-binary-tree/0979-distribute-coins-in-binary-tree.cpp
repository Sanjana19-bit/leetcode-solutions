class Solution {
public:
    int ans = 0;
    int dfs(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        ans += abs(left) + abs(right);
        return left + right + root->val - 1;
    }
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return ans;
    }
};