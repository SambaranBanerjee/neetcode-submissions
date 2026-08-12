class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0; //0 coins required to make amount 0
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (i - coin >= 0) {
                    dp[i] = min(1 + dp[i - coin], dp[i]);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount]; //Because at max number of coins can be equal to amount
    }
};
