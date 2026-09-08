class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {

        queue<pair<TreeNode*, TreeNode*>> q;

        q.push({root, NULL});

        while (!q.empty()) {

            int size = q.size();

            TreeNode* parentX = NULL;
            TreeNode* parentY = NULL;







            for (int i = 0; i < size; i++) {

                auto [node, parent] = q.front();
                q.pop();

                if (node->val == x) {
                    parentX = parent;
                }

                if (node->val == y) {
                    parentY = parent;
                }

                if (node->left) {
                    q.push({node->left, node});
                }

                if (node->right) {
                    q.push({node->right, node});
                }
            }

            if (parentX != NULL && parentY != NULL) {
                return parentX != parentY;
            }

            if (parentX != NULL || parentY != NULL) {
                return false;
            }
        }

        return false;
    }
};