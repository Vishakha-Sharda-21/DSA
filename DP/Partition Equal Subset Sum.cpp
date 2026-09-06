class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);

        // Odd total sum can never be divided equally
        if (total & 1) return false;

        int target = total / 2;

        // dp[s] = whether sum s can be formed
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int num : nums) {
            // Traverse backwards so each number is used only once
            for (int sum = target; sum >= num; --sum) {
                dp[sum] = dp[sum] || dp[sum - num];
            }

            // Target reached early
            if (dp[target]) return true;
        }

        return false;
    }
};
