class Solution {
private:
    unordered_set<string> wordSet;
    vector<int> memo;

    bool dfs(const string& s, int start) {
        if (start == s.size()) {
            return true;
        }
        if (memo[start] != -1) {
            return memo[start];
        }
        for (int end = start + 1; end <= s.size(); end++) {
            string word = s.substr(start, end - start);

            if (wordSet.count(word) && dfs(s,end)) {
                return memo[start] = true;
            }
        }
        return memo[start] = false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        wordSet = unordered_set<string>(wordDict.begin(),wordDict.end());
        memo.assign(n, -1);
        return dfs(s, 0);
    }
};
