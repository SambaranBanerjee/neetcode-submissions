class Solution {
private:
    int solve(string& s, int i, int& n,vector<int>& dp) {
        if (i == n) {
            return 1;
        }

        if (s[i] == '0') {
            return 0;
        }

        if (dp[i] != -1) {
            return dp[i];
        }
    
        int single_digit_cases = solve(s, i + 1, n, dp);
        int double_digit_cases = 0;
        if (i + 1 < n) {
            if (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')) {
                double_digit_cases = solve(s, i + 2, n, dp);
            }
        }
        return dp[i] = single_digit_cases + double_digit_cases;
    }
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int>dp(n + 1,-1);
        return solve(s,0,n,dp);
    }
};
