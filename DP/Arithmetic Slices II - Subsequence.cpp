class Solution {
public:
    struct CustomHash {
        static uint64_t splitmix64(uint64_t x) {
            x += 0x9e3779b97f4a7c15;
            x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
            x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
            return x ^ (x >> 31);
        }

        size_t operator()(long long x) const {
            static const uint64_t FIXED_RANDOM =
                chrono::steady_clock::now().time_since_epoch().count();

            return splitmix64(x + FIXED_RANDOM);
        }
    };

public:
    int numberOfArithmeticSlices(vector<int>& nums) {

        int n = nums.size();

        vector<unordered_map<long long, int, CustomHash>> dp(n);

        long long ans = 0;

        for (int i = 0; i < n; i++) {

            // Reduce rehashing overhead
            dp[i].reserve(i * 2 + 1);

            for (int j = 0; j < i; j++) {

                long long diff =
                    (long long)nums[i] - nums[j];

                auto it = dp[j].find(diff);

                int previous = 0;

                if (it != dp[j].end()) {
                    previous = it->second;
                }

                dp[i][diff] += previous + 1;

                ans += previous;
            }
        }

        return (int)ans;
    }
};
