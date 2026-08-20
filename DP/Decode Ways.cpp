class Solution {
public:
    int numDecodings(string s) {
        int prev2 = 1; // dp[i-2]
        int prev1 = 1; // dp[i-1]

        for (int i = 1; i <= s.size(); i++) {
            int cur = 0;

            // Decode one digit
            if (s[i - 1] != '0') {
                cur += prev1;
            }

            // Decode two digits
            if (i >= 2) {
                int two = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');

                if (two >= 10 && two <= 26) {
                    cur += prev2;
                }
            }

            prev2 = prev1;
            prev1 = cur;
        }

        return prev1;
    }
};
