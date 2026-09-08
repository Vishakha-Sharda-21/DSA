class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();

        // Keep DP width as small as possible
        if (n <= m) {
            int dp[201];
            
            for (int j = 0; j <= n; ++j)
                dp[j] = 1000000000;

            dp[n - 1] = 1;

            for (int i = m - 1; i >= 0; --i) {
                for (int j = n - 1; j >= 0; --j) {
                    int need = dp[j] < dp[j + 1] ? dp[j] : dp[j + 1];
                    int cur = need - dungeon[i][j];
                    dp[j] = cur > 1 ? cur : 1;
                }
            }

            return dp[0];
        }

        // Process transposed logically when rows < columns
        int dp[201];

        for (int i = 0; i <= m; ++i)
            dp[i] = 1000000000;

        dp[m - 1] = 1;

        for (int j = n - 1; j >= 0; --j) {
            for (int i = m - 1; i >= 0; --i) {
                int need = dp[i] < dp[i + 1] ? dp[i] : dp[i + 1];
                int cur = need - dungeon[i][j];
                dp[i] = cur > 1 ? cur : 1;
            }
        }

        return dp[0];
    }
};
