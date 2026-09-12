class Solution {
public:
    struct State {
        long long score = 0;
        int cnt = 0;
        array<int, 4> ids = {-1, -1, -1, -1};
    };

    bool better(const State& a, const State& b) {
        // Higher score is better
        if (a.score != b.score)
            return a.score > b.score;

        // Lexicographically smaller index array is better
        int len = min(a.cnt, b.cnt);

        for (int i = 0; i < len; i++) {
            if (a.ids[i] != b.ids[i])
                return a.ids[i] < b.ids[i];
        }

        // If one is a prefix of the other,
        // the shorter one is lexicographically smaller.
        return a.cnt < b.cnt;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // {right, left, weight, original index}
        vector<array<long long, 4>> a(n);

        for (int i = 0; i < n; i++) {
            a[i] = {
                intervals[i][1],
                intervals[i][0],
                intervals[i][2],
                i
            };
        }

        // Sort by right endpoint
        sort(a.begin(), a.end(), [](const auto& x, const auto& y) {
            if (x[0] != y[0])
                return x[0] < y[0];

            return x[1] < y[1];
        });

        // Store all right endpoints
        vector<long long> ends(n);

        for (int i = 0; i < n; i++)
            ends[i] = a[i][0];

        /*
            prev[i] = number of intervals among [0 ... i-1]
                      whose right endpoint < a[i].left

            We use lower_bound because equality is NOT allowed.

            Example:
                previous right = 5
                current left   = 5

                They overlap.

                Therefore we need:
                    previous right < current left
        */
        vector<int> prev(n);

        for (int i = 0; i < n; i++) {
            prev[i] =
                lower_bound(ends.begin(),
                            ends.begin() + i,
                            a[i][1]) - ends.begin();
        }

        /*
            dp[k][i]

            Best answer using at most k intervals
            from the first i sorted intervals.

            i ranges from 0 to n.
        */
        vector<array<State, 5>> dp(n + 1);

        for (int i = 1; i <= n; i++) {

            // Current interval is a[i - 1]
            int idx = i - 1;

            // First copy "don't take this interval"
            for (int k = 1; k <= 4; k++) {
                dp[i][k] = dp[i - 1][k];
            }

            // Try taking current interval
            for (int k = 1; k <= 4; k++) {

                int p = prev[idx];

                State take = dp[p][k - 1];

                take.score += a[idx][2];

                // Add original index
                int originalIndex = (int)a[idx][3];

                take.ids[take.cnt++] = originalIndex;

                /*
                    dp is sorted by ending position, not original index.

                    The final answer must be lexicographically smallest,
                    so sort the maximum 4 indices manually.
                */
                for (int x = take.cnt - 1; x > 0; x--) {
                    if (take.ids[x] < take.ids[x - 1]) {
                        swap(take.ids[x], take.ids[x - 1]);
                    } else {
                        break;
                    }
                }

                if (better(take, dp[i][k])) {
                    dp[i][k] = take;
                }
            }
        }

        State ans = dp[n][4];

        vector<int> result;

        for (int i = 0; i < ans.cnt; i++)
            result.push_back(ans.ids[i]);

        return result;
    }
};
