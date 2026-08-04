class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mn = nums[0], mx = nums[0];
        bool present[101] = {};

        for (int x : nums) {
            present[x] = true;
            mn = min(mn, x);
            mx = max(mx, x);
        }

        vector<int> ans;

        for (int i = mn; i <= mx; i++) {
            if (!present[i]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
