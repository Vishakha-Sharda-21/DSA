
class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());

        vector<pair<int, int>> sortedQueries;
        for (int i = 0; i < queries.size(); i++) {
            sortedQueries.push_back({queries[i], i});
        }

        sort(sortedQueries.begin(), sortedQueries.end());

        // {interval length, right endpoint}
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        vector<int> ans(queries.size(), -1);
        int i = 0, n = intervals.size();

        for (auto& [query, index] : sortedQueries) {
            // Add intervals that start at or before this query.
            while (i < n && intervals[i][0] <= query) {
                int left = intervals[i][0];
                int right = intervals[i][1];
                pq.push({right - left + 1, right});
                i++;
            }

            // Remove intervals that cannot contain this query.
            while (!pq.empty() && pq.top().second < query) {
                pq.pop();
            }

            // The smallest valid interval is at the top.
            if (!pq.empty()) {
                ans[index] = pq.top().first;
            }
        }

        return ans;
    }
};
