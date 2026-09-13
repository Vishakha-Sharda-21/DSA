class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        const int INF = 1e9;

        vector<int> cost(n, INF);
        cost[src] = 0;

        // At most k stops = at most k + 1 flights
        for (int i = 0; i <= k; i++) {

            vector<int> next = cost;

            for (auto &flight : flights) {
                int from = flight[0];
                int to = flight[1];
                int price = flight[2];

                if (cost[from] != INF) {
                    next[to] = min(next[to],
                                   cost[from] + price);
                }
            }

            cost = next;
        }

        return cost[dst] == INF ? -1 : cost[dst];
    }
};
