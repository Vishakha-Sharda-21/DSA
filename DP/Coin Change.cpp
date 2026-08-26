class Solution {
public:
    int memo[10001];
    int dfs(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        if (memo[amount] != -1) return memo[amount];

        long long res = 2e9;
        for (int coin : coins) {
            if (amount - coin >= 0) {
                res = min(res,
                      1LL + dfs(coins, amount - coin));
            }
        }
        return memo[amount] = res;
    }

    int coinChange(vector<int>& coins, int amount) {
        fill(begin(memo), end(memo), -1);
        int minCoins = dfs(coins, amount);
        return (minCoins >= 1e9) ? -1 : minCoins;
    }
};
