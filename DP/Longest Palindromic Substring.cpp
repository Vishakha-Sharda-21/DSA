class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), st = 0, len = 1;

        auto expand = [&](int l, int r) {
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > len) {
                    len = r - l + 1;
                    st = l;
                }
                l--;
                r++;
            }
        };

        for (int i = 0; i < n; i++) {
            expand(i, i);       // Odd length
            expand(i, i + 1);   // Even length
        }

        return s.substr(st, len);
    }
};
