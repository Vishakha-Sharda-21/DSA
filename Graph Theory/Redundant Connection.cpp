class Solution {
public:
    vector<int> parent;

    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1);

        for (int i = 1; i <= n; i++)
            parent[i] = i;

        for (auto &e : edges) {
            int a = find(e[0]);
            int b = find(e[1]);

            // Already connected => cycle
            if (a == b)
                return e;

            parent[a] = b;
        }

        return {};
    }
};
