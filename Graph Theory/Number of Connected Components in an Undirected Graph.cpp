class Solution {
public:
    vector<int> parent, rank_;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // Path compression

        return parent[x];
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        // Already in the same component
        if (a == b)
            return false;

        // Union by rank
        if (rank_[a] < rank_[b])
            swap(a, b);

        parent[b] = a;

        if (rank_[a] == rank_[b])
            rank_[a]++;

        return true;
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank_.assign(n, 0);

        // Initially every node is a separate component
        for (int i = 0; i < n; i++)
            parent[i] = i;

        int components = n;

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            // If two components merge
            if (unite(u, v))
                components--;
        }

        return components;
    }
};
