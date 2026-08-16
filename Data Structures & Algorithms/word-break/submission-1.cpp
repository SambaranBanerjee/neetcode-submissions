class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> wordSet(wordDict.begin(),wordDict.end());
        
        vector<bool> dp(n + 1,false);
        dp[n] = true;

        for (int i = n - 1; i >= 0; i--) {
            for (string& elem : wordDict) {
                if ((i + elem.size()) <= s.size() && s.substr(i, elem.size()) == elem) {
                    dp[i] = dp[i + elem.size()];
                }
                if (dp[i]) {
                    break;
                }
            }
        }
        
        return dp[0];
    }
};
