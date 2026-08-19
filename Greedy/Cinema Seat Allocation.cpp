class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> mp;

        // Build bitmask for every row
        for (auto &x : reservedSeats) {
            int row = x[0];
            int seat = x[1];

            mp[row] |= (1 << seat);
        }

        // Every completely empty row can fit 2 groups
        int ans = 2 * (n - mp.size());

        // Masks:
        // 2-5
        int left = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);

        // 4-7
        int middle = (1 << 4) | (1 << 5) |
                     (1 << 6) | (1 << 7);

        // 6-9
        int right = (1 << 6) | (1 << 7) |
                    (1 << 8) | (1 << 9);

        for (auto &[row, mask] : mp) {

            bool L = (mask & left) == 0;
            bool M = (mask & middle) == 0;
            bool R = (mask & right) == 0;

            // Can place two groups only on left + right
            if (L && R)
                ans += 2;

            // Otherwise, if any block works
            else if (L || M || R)
                ans += 1;
        }

        return ans;
    }
};
