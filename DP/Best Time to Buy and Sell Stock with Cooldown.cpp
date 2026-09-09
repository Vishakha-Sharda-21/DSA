class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold = -prices[0]; // Max profit while holding stock
        int sold = 0;          // Max profit after selling today
        int rest = 0;          // Max profit while in cooldown/rest

        for (int i = 1; i < prices.size(); ++i) {
            int prevHold = hold;
            int prevSold = sold;
            int prevRest = rest;

            // Either keep holding or buy after resting
            hold = max(prevHold, prevRest - prices[i]);

            // Sell the stock today
            sold = prevHold + prices[i];

            // Either stay resting or remain in cooldown
            rest = max(prevRest, prevSold);
        }

        return max(sold, rest);
    }
};
