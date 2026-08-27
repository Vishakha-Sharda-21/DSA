class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int base[26] = {};
        for (char c : s) base[c - 'a']++;

        int n = s.size();

        // Try making the answer greater at position i
        // from right to left.
        for (int i = n - 1; i >= 0; i--) {
            int cnt[26];
            memcpy(cnt, base, sizeof(cnt));

            // Prefix must exactly match target
            bool ok = true;
            for (int j = 0; j < i; j++) {
                int x = target[j] - 'a';
                if (!cnt[x]) {
                    ok = false;
                    break;
                }
                cnt[x]--;
            }

            if (!ok) continue;

            // Pick the smallest character > target[i]
            int x = target[i] - 'a';
            for (int c = x + 1; c < 26; c++) {
                if (!cnt[c]) continue;

                string ans = target.substr(0, i);
                ans += char('a' + c);
                cnt[c]--;

                // Smallest possible suffix
                for (int k = 0; k < 26; k++)
                    ans.append(cnt[k], char('a' + k));

                return ans;
            }
        }

        return "";
    }
};
