class Solution {
public:
    vector<int> parent, rank_;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);

        return parent[x];
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        // Same parent means adding this edge creates a cycle.
        if (a == b)
            return false;

        if (rank_[a] < rank_[b])
            swap(a, b);

        parent[b] = a;

        if (rank_[a] == rank_[b])
            rank_[a]++;

        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        // A tree with n nodes must have exactly n - 1 edges.
        if (edges.size() != n - 1)
            return false;

        parent.resize(n);
        rank_.assign(n, 0);

        iota(parent.begin(), parent.end(), 0);

        for (auto& edge : edges) {
            if (!unite(edge[0], edge[1]))
                return false;  // Cycle detected
        }

        return true;
    }
};
