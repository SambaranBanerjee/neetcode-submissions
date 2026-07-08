class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maximumProfit = 0;
        int n = prices.size();
        for (int i = 0; i < n; i++) {
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            }
            else {
                maximumProfit = max(maximumProfit, prices[i] - minPrice);
            }
        }
        return maximumProfit;
    }
};
