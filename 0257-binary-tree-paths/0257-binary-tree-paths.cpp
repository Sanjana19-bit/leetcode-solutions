class Solution {
public:
    void solve(TreeNode* root, string path, vector<string>& ans) {
        if (root == nullptr)
            return;
        path += to_string(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            ans.push_back(path);
            return;
        }

        if (root->left != nullptr) {
            solve(root->left, path + "->", ans);
        }
        if (root->right != nullptr) {
            solve(root->right, path + "->", ans);
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;

        solve(root, "", ans);

        return ans;
    }
};