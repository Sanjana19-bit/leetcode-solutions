class Solution {
public:

    pair<int, int> dfs(TreeNode* root, int &ans) {

        if (root == NULL)
            return {0, 0};

        pair<int, int> left = dfs(root->left, ans);
        pair<int, int> right = dfs(root->right, ans);

        int sum = left.first + right.first + root->val;
        int count = left.second + right.second + 1;

        int average = sum / count;

        if (average == root->val)
            ans++;

        return {sum, count};
    }

    int averageOfSubtree(TreeNode* root) {

        int ans = 0;

        dfs(root, ans);

        return ans;
    }
};