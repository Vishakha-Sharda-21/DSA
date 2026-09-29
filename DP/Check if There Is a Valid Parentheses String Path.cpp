class Solution {
public:
    bool hasValidPath(vector<vector<char>>& g) {
        int m = g.size(), n = g[0].size();
        if ((m + n - 1) % 2 || g[0][0] == ')' || g[m-1][n-1] == '(')
            return false;

        vector<bitset<201>> dp(n);
        dp[0][1] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!i && !j) continue;

                bitset<201> s = dp[j] | (j ? dp[j-1] : bitset<201>());

                if (g[i][j] == '(') s <<= 1;
                else s >>= 1;

                dp[j] = s;
            }
        }

        return dp[n-1][0];
    }
};
