class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int freq[2001] = {};

        for (int x : nums) {
            freq[x + 1000]++;
        }

        for (int x = 2000; x >= 0; x--) {
            k -= freq[x];

            if (k <= 0) {
                return x - 1000;
            }
        }

        return -1;
    }
};
