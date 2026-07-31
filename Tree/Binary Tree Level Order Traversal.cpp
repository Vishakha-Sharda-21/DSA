class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};

        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();
            ans.emplace_back();

            while (sz--) {
                TreeNode* node = q.front();
                q.pop();

                ans.back().push_back(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }

        return ans;
    }
};
