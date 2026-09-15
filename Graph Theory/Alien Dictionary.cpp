class Solution {
public:
    string foreignDictionary(vector<string>& words) {

        vector<vector<int>> graph(26);
        vector<int> state(26, 0);
        vector<bool> exists(26, false);

        // Find all characters
        for (string &word : words) {
            for (char c : word) {
                exists[c - 'a'] = true;
            }
        }

        // Build graph
        for (int i = 0; i + 1 < words.size(); i++) {

            string &a = words[i];
            string &b = words[i + 1];

            int len = min(a.size(), b.size());
            int j = 0;

            // Find first different character
            while (j < len && a[j] == b[j]) {
                j++;
            }

            // Invalid prefix case
            // Example: ["abc", "ab"]
            if (j == len) {
                if (a.size() > b.size()) {
                    return "";
                }

                continue;
            }

            int u = a[j] - 'a';
            int v = b[j] - 'a';

            graph[u].push_back(v);
        }

        string ans;

        // Topological sort using DFS
        for (int i = 0; i < 26; i++) {

            if (exists[i] && state[i] == 0) {

                if (!dfs(i, graph, state, ans)) {
                    return "";
                }
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }

private:
    bool dfs(int u,
             vector<vector<int>>& graph,
             vector<int>& state,
             string& ans) {

        // Cycle detected
        if (state[u] == 1) {
            return false;
        }

        // Already processed
        if (state[u] == 2) {
            return true;
        }

        state[u] = 1;

        for (int v : graph[u]) {

            if (!dfs(v, graph, state, ans)) {
                return false;
            }
        }

        state[u] = 2;

        ans += char('a' + u);

        return true;
    }
};
