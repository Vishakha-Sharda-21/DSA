class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *first = nullptr;
        TreeNode *second = nullptr;
        TreeNode *prev = nullptr;
        TreeNode *cur = root;

        while (cur) {
            if (!cur->left) {
                // Visit current node
                if (prev && prev->val > cur->val) {
                    if (!first)
                        first = prev;
                    second = cur;
                }

                prev = cur;
                cur = cur->right;
            }
            else {
                // Find inorder predecessor
                TreeNode* pred = cur->left;

                while (pred->right && pred->right != cur)
                    pred = pred->right;

                if (!pred->right) {
                    // Create temporary thread
                    pred->right = cur;
                    cur = cur->left;
                }
                else {
                    // Remove temporary thread
                    pred->right = nullptr;

                    // Visit current node
                    if (prev && prev->val > cur->val) {
                        if (!first)
                            first = prev;
                        second = cur;
                    }

                    prev = cur;
                    cur = cur->right;
                }
            }
        }

        swap(first->val, second->val);
    }
};
