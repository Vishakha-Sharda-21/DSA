class Solution {
public:
    int countDigitOne(int n) {
        long long ans = 0;

        for (long long f = 1; f <= n; f *= 10) {
            long long high = n / (f * 10);
            long long cur = (n / f) % 10;
            long long low = n % f;

            if (cur == 0)
                ans += high * f;
            else if (cur == 1)
                ans += high * f + low + 1;
            else
                ans += (high + 1) * f;
        }

        return ans;
    }
};
