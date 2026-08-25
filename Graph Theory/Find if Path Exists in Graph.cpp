class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> g(n);
        
        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n);
        queue<int> q;
        q.push(source);
        vis[source] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (u == destination) return true;

            for (int v : g[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }

        return false;
    }
};
