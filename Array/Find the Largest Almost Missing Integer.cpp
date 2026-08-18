class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        // windowCount[x] = number of size-k subarrays
        // that contain x
        vector<int> windowCount(51, 0);

        // Check every subarray of size k
        for (int i = 0; i <= n - k; i++) {
            vector<bool> seen(51, false);

            for (int j = i; j < i + k; j++) {
                int x = nums[j];

                // Count x only once for this window
                if (!seen[x]) {
                    seen[x] = true;
                    windowCount[x]++;
                }
            }
        }

        // Find the largest integer appearing in exactly one window
        for (int x = 50; x >= 0; x--) {
            if (windowCount[x] == 1) {
                return x;
            }
        }

        return -1;
    }
};
