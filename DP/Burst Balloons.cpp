class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> a(n + 2, 1);

        for (int i = 0; i < n; ++i)
            a[i + 1] = nums[i];

        n += 2;
        vector<vector<int>> dp(n, vector<int>(n));

        for (int len = 2; len < n; ++len) {
            for (int l = 0; l + len < n; ++l) {
                int r = l + len;
                for (int k = l + 1; k < r; ++k)
                    dp[l][r] = max(dp[l][r],
                                   dp[l][k] + dp[k][r] + a[l] * a[k] * a[r]);
            }
        }

        return dp[0][n - 1];
    }
};
