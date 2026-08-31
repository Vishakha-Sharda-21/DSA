class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), ans = 0;

        for (int i = 0; i < n; i++) {
            // Odd-length palindromes
            for (int l = i, r = i; l >= 0 && r < n && s[l] == s[r]; l--, r++)
                ans++;

            // Even-length palindromes
            for (int l = i, r = i + 1; l >= 0 && r < n && s[l] == s[r]; l--, r++)
                ans++;
        }

        return ans;
    }
};
