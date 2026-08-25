class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        auto solve = [&](int l, int r) {
            int prev = 0, curr = 0;

            for (int i = l; i <= r; i++) {
                int next = max(curr, prev + nums[i]);
                prev = curr;
                curr = next;
            }
            return curr;
        };

        return max(solve(0, n - 2), solve(1, n - 1));
    }
};
