class Solution {
public:
    int romanToInt(string s) {
        int val[26] = {};
        val['I' - 'A'] = 1;
        val['V' - 'A'] = 5;
        val['X' - 'A'] = 10;
        val['L' - 'A'] = 50;
        val['C' - 'A'] = 100;
        val['D' - 'A'] = 500;
        val['M' - 'A'] = 1000;

        int ans = 0, prev = 0;

        for (int i = s.size() - 1; i >= 0; --i) {
            int cur = val[s[i] - 'A'];
            if (cur < prev)
                ans -= cur;
            else {
                ans += cur;
                prev = cur;
            }
        }

        return ans;
    }
};
