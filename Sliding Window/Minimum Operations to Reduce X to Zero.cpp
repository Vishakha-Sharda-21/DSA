class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        long long target = -x;

        for (int v : nums)
            target += v;

        if (target < 0) return -1;
        if (target == 0) return n;

        long long sum = 0;
        int l = 0, best = -1;

        for (int r = 0; r < n; ++r) {
            sum += nums[r];

            while (sum > target)
                sum -= nums[l++];

            if (sum == target) {
                int len = r - l + 1;
                if (len > best)
                    best = len;
            }
        }

        return best < 0 ? -1 : n - best;
    }
};
