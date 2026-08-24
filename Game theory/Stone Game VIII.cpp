class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        // Sum of all stones = prefix[n - 1]
        long long prefix = 0;

        for (int x : stones) {
            prefix += x;
        }

        // dp = best score difference starting from the
        // state where Alice takes all stones.
        long long dp = prefix;

        // Move from prefix[n-2] down to prefix[1]
        for (int i = n - 2; i >= 1; --i) {
            
            // Remove stones[i + 1] to get prefix[i]
            prefix -= stones[i + 1];

            // Current player takes prefix[i]
            // and opponent gets dp advantage.
            dp = max(dp, prefix - dp);
        }

        return (int)dp;
    }
};
