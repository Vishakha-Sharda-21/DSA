class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        // Impossible cases
        if (abs(target) > totalSum)
            return 0;

        if ((totalSum + target) % 2 != 0)
            return 0;

        int subsetSum = (totalSum + target) / 2;

        // dp[s] = number of ways to make sum s
        vector<int> dp(subsetSum + 1, 0);
        dp[0] = 1;

        for (int num : nums) {
            // Traverse backwards because each number
            // can be used only once.
            for (int sum = subsetSum; sum >= num; --sum) {
                dp[sum] += dp[sum - num];
            }
        }

        return dp[subsetSum];
    }
};
