class Solution {
private:
    vector<int> memo;
    int dfs(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }
        if (amount < 0) {
            return 1e9;
        }
        if (memo[amount] != -1) {
            return memo[amount];
        }
        int minCoins = 1e9;
        for (int coin : coins) {
            int res = dfs(coins,amount - coin);
            if (res != 1e9) {
                minCoins = min(minCoins, 1 + res);
            }
        }
        return memo[amount] = minCoins;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        memo.assign(amount + 1, -1); //Atmost 12 places can be there each filled with 1
        int result = dfs(coins,amount);
        return result >= 1e9 ? -1 : result;
    }
};
