class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0)
                continue;

            bool possible = true;
            int prevMax = -1;

            for (int start = 0; start < n && possible; start += k) {
                int mn = nums[start];
                int mx = nums[start];
                int descents = 0;

                for (int j = 0; j < k; j++) {
                    int cur = nums[start + j];
                    int next = nums[start + (j + 1) % k];

                    mn = min(mn, cur);
                    mx = max(mx, cur);

                    if (cur > next)
                        descents++;
                }

                if (descents > 1) {
                    possible = false;
                    break;
                }

                if (start > 0 && prevMax > mn) {
                    possible = false;
                    break;
                }

                prevMax = mx;
            }

            if (possible)
                ans += k;
        }

        return ans;
    }
};
