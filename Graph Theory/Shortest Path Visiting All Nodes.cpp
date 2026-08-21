class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();

        // All nodes visited
        int target = (1 << n) - 1;

        // dist[node][mask]
        // Use uint8_t because answer is small (n <= 12)
        vector<vector<unsigned char>> dist(
            n, vector<unsigned char>(1 << n, 255)
        );

        // Queue encoded as: mask * n + node
        vector<int> q;
        q.reserve(n * (1 << n));

        // Multi-source BFS:
        // We can start from ANY node.
        for (int i = 0; i < n; ++i) {
            int mask = 1 << i;
            dist[i][mask] = 0;
            q.push_back(mask * n + i);
        }

        size_t head = 0;

        while (head < q.size()) {
            int state = q[head++];

            int mask = state / n;
            int node = state % n;

            int d = dist[node][mask];

            if (mask == target)
                return d;

            for (int next : graph[node]) {
                int newMask = mask | (1 << next);

                if (dist[next][newMask] == 255) {
                    dist[next][newMask] = d + 1;
                    q.push_back(newMask * n + next);
                }
            }
        }

        return -1;
    }
};
