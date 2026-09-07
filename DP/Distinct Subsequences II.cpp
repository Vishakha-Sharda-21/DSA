class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1e9 + 7;

        // dp = number of distinct subsequences including empty subsequence
        long long dp = 1;

        // last[c] = number of distinct subsequences before
        // the previous occurrence of character c
        vector<long long> last(26, 0);

        for (char ch : s) {
            int c = ch - 'a';

            long long newDp = (2 * dp - last[c] + MOD) % MOD;

            // For future occurrences of this character,
            // this is the value that must be subtracted.
            last[c] = dp;

            dp = newDp;
        }

        // Remove the empty subsequence
        return (dp - 1 + MOD) % MOD;
    }
};
