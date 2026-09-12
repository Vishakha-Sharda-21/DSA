class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();

        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        // dp[i] = true if s[0...i-1] can be segmented
        vector<bool> dp(n + 1, false);

        dp[0] = true;

        for (int i = 1; i <= n; i++) {

            for (int j = 0; j < i; j++) {

                if (!dp[j])
                    continue;

                // s[j...i-1]
                if (dict.find(s.substr(j, i - j)) != dict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};
