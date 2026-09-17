class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {

        int n = arr.size();
        const int INF = 1e9;

        // best[i] = minimum length of a valid subarray
        // completely inside arr[0 ... i-1]
        vector<int> best(n + 1, INF);

        int ans = INF;

        int left = 0;
        long long sum = 0;

        for (int right = 0; right < n; right++) {

            sum += arr[right];

            // Since all numbers are positive,
            // shrink while sum is too large.
            while (sum > target) {
                sum -= arr[left];
                left++;
            }

            // We found a subarray [left ... right]
            if (sum == target) {

                int len = right - left + 1;

                // Previous subarray must end before 'left'
                if (best[left] != INF) {
                    ans = min(ans, len + best[left]);
                }

                // This is the shortest valid subarray
                // seen so far up to 'right'.
                best[right + 1] = min(best[right], len);
            }
            else {
                // Carry forward the best answer
                best[right + 1] = best[right];
            }
        }

        return ans == INF ? -1 : ans;
    }
};
