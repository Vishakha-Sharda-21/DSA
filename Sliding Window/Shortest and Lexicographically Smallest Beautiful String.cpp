class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size(), l = 0, ones = 0, best = n + 1;
        string ans = "";

        for (int r = 0; r < n; r++) {
            ones += s[r] == '1';

            while (ones > k)
                ones -= s[l++] == '1';

            if (ones == k) {
                while (s[l] == '0') l++;

                int len = r - l + 1;

                if (len < best) {
                    best = len;
                    ans = s.substr(l, len);
                } 
                else if (len == best) {
                    string cur = s.substr(l, len);
                    if (cur < ans) ans = cur;
                }
            }
        }

        return ans;
    }
};
