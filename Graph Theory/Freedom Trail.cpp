class Solution {
public:
    int n, m;
    string r, k;
    int dp[101][101];

    int solve(int keyIndex, int ringPos) {
        if (keyIndex == m)
            return 0;

        if (dp[keyIndex][ringPos] != -1)
            return dp[keyIndex][ringPos];

        int ans = INT_MAX;

        for (int nextPos = 0; nextPos < n; nextPos++) {

            if (r[nextPos] == k[keyIndex]) {

                int clockwise = abs(nextPos - ringPos);

                int anticlockwise = n - clockwise;

                int rotateSteps = min(clockwise, anticlockwise);

                int total = rotateSteps
                          + 1
                          + solve(keyIndex + 1, nextPos);

                ans = min(ans, total);
            }
        }

        return dp[keyIndex][ringPos] = ans;
    }

    int findRotateSteps(string ring, string key) {
        r = ring;
        k = key;

        n = r.length();
        m = k.length();

        memset(dp, -1, sizeof(dp));

        return solve(0, 0);
    }
};
