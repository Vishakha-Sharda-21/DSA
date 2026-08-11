class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];

        // Find longest sequential prefix
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1)
                sum += nums[i];
            else
                break;
        }

        // Mark existing numbers
        bool present[101] = {};
        for (int x : nums)
            present[x] = true;

        // Find smallest missing >= sum
        while (sum <= 100 && present[sum])
            sum++;

        return sum;
    }
};
