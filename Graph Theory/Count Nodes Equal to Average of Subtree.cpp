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
    int ans = 0;

    void dfs(TreeNode* root, int& sum, int& count) {
        if (root == NULL) {
            sum = 0;
            count = 0;
            return;
        }

        int leftSum, leftCount;
        int rightSum, rightCount;

        dfs(root->left, leftSum, leftCount);
        dfs(root->right, rightSum, rightCount);

        sum = leftSum + rightSum + root->val;
        count = leftCount + rightCount + 1;

        if (root->val == sum / count) {
            ans++;
        }
    }

    int averageOfSubtree(TreeNode* root) {
        int sum, count;

        dfs(root, sum, count);

        return ans;
    }
};
