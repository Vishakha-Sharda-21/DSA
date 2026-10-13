
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int ans = 0;

        int dirs[5] = {-1, 0, 1, 0, -1};

        auto dfs = [&](auto&& self, int r, int c) -> int {
            if (dp[r][c]) return dp[r][c];

            dp[r][c] = 1;

            for (int d = 0; d < 4; d++) {
                int nr = r + dirs[d];
                int nc = c + dirs[d + 1];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                    matrix[nr][nc] > matrix[r][c]) {
                    dp[r][c] = max(dp[r][c],
                                   1 + self(self, nr, nc));
                }
            }

            return dp[r][c];
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, dfs(dfs, i, j));
            }
        }

        return ans;
    }
};
