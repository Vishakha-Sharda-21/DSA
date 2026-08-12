class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp.reserve(nums.size() * 2);
        mp.max_load_factor(0.7);

        int l = 0, ans = 0;

        for (int r = 0; r < nums.size(); ++r) {
            if (++mp[nums[r]] > k) {
                while (mp[nums[r]] > k)
                    --mp[nums[l++]];
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};
