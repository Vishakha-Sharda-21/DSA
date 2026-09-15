class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        vector<int> dp(n + 1, 0);

        for (int i = 0; i < n; i++) {
            dp[i + 1] = max(dp[i + 1], dp[i]);

            // Odd length palindrome
            int l = i, r = i;

            while (l >= 0 && r < n && s[l] == s[r]) {
                int len = r - l + 1;

                if (len >= k) {
                    dp[r + 1] = max(dp[r + 1], dp[l] + 1);
                }

                l--;
                r++;
            }

            // Even length palindrome
            l = i;
            r = i + 1;

            while (l >= 0 && r < n && s[l] == s[r]) {
                int len = r - l + 1;

                if (len >= k) {
                    dp[r + 1] = max(dp[r + 1], dp[l] + 1);
                }

                l--;
                r++;
            }
        }

        return dp[n];
    }
};
