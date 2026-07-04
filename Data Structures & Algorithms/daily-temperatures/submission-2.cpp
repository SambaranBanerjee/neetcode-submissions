class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result;
        for (int i = 0; i < n; i++) {
            int days = 1;
            int a = i + 1;
            while (a < n && temperatures[a] <= temperatures[i]) {
                days++;
                a++;
            }
            if (a > n - 1) {
                result.push_back(0);
                continue;
            }
            result.push_back(days);
        }
        return result;
    }
};
