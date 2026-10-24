class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;

        for (int i = 1; i < n; ++i) {
            int diff = prices[i] - prices[i - 1];
            profit += (diff > 0) * diff;
        }

        return profit;
    }
};
