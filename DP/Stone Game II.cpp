class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        int suffix[105] = {};
        for (int i = n - 1; i >= 0; --i)
            suffix[i] = suffix[i + 1] + piles[i];

        int dp[105][105] = {};

        for (int i = n - 1; i >= 0; --i) {
            for (int m = 1; m <= n; ++m) {

                if (i + 2 * m >= n) {
                    dp[i][m] = suffix[i];
                    continue;
                }

                int best = 0;

                for (int x = 1; x <= 2 * m && i + x <= n; ++x) {
                    int nextM = max(m, x);

                    best = max(
                        best,
                        suffix[i] - dp[i + x][nextM]
                    );
                }

                dp[i][m] = best;
            }
        }

        return dp[0][1];
    }
};
