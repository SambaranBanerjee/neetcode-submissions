#include <cstring>
class Solution {
private:
    int memo[101];
    int solve(string& s, int i, int& n) {
        if (i == n) {
            return memo[i] = 1;
        }

        if (s[i] == '0') {
            return memo[i] = 0;
        }

        if (memo[i] != -1) {
            return memo[i];
        }
    
        int single_digit_cases = solve(s, i + 1, n);
        int double_digit_cases = 0;
        if (i + 1 < n) {
            if (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')) {
                double_digit_cases = solve(s, i + 2, n);
            }
        }
        return memo[i] = single_digit_cases + double_digit_cases;
    }
public:
    int numDecodings(string s) {
        int n = s.length();
        memset(memo, -1, sizeof(memo));
        return solve(s,0,n);
    }
};
