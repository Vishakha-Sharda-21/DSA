class Solution {
    unordered_map<string, priority_queue<
        string,
        vector<string>,
        greater<string>
    >> graph;

    vector<string> ans;

    void dfs(const string& airport) {
        auto& pq = graph[airport];

        while (!pq.empty()) {
            string next = pq.top();
            pq.pop();

            dfs(next);
        }

        // Add after using all outgoing edges
        ans.push_back(airport);
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (const auto& ticket : tickets) {
            graph[ticket[0]].push(ticket[1]);
        }

        dfs("JFK");

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
