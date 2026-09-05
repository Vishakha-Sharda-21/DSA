class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<int> minDist(n, INT_MAX);
        vector<bool> used(n, false);

        minDist[0] = 0;

        int totalCost = 0;

        for (int count = 0; count < n; ++count) {

            // Find the unused point with minimum connection cost
            int u = -1;

            for (int i = 0; i < n; ++i) {
                if (!used[i] && (u == -1 || minDist[i] < minDist[u])) {
                    u = i;
                }
            }

            // Add this edge to MST
            used[u] = true;
            totalCost += minDist[u];

            // Update minimum cost for remaining points
            for (int v = 0; v < n; ++v) {
                if (!used[v]) {
                    int cost = abs(points[u][0] - points[v][0]) +
                               abs(points[u][1] - points[v][1]);

                    minDist[v] = min(minDist[v], cost);
                }
            }
        }

        return totalCost;
    }
};
