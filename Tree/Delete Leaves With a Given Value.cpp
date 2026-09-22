class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (!root) return nullptr;

        vector<pair<TreeNode*, bool>> st;
        st.reserve(6000);

        st.push_back({root, false});

        while (!st.empty()) {
            auto [node, visited] = st.back();
            st.pop_back();

            if (!node) continue;

            if (!visited) {
                st.push_back({node, true});
                st.push_back({node->right, false});
                st.push_back({node->left, false});
            } 
            else {
                if (!node->left && !node->right && node->val == target) {
                    // Parent will remove this through its pointer.
                    continue;
                }
            }
        }

        // The above traversal needs parent pointers to actually unlink.
        // Use the following pointer-to-pointer implementation instead.
        return remove(root, target);
    }

private:
    TreeNode* remove(TreeNode* node, int target) {
        if (!node) return nullptr;

        node->left = remove(node->left, target);
        node->right = remove(node->right, target);

        return (!node->left && !node->right && node->val == target)
                   ? nullptr
                   : node;
    }
};
