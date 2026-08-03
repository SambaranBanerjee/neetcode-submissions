class Solution {
    vector<vector<string>> result;
    vector<string> current;
    bool isPalindrome(string s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    void dfs(string s, int strIdx) {
        if (strIdx == s.size()) {
            result.push_back(current);
            return;
        }

        for (int i = strIdx; i < s.size(); i++) {
            if (isPalindrome(s,strIdx,i)) {
                current.push_back(s.substr(strIdx, i - strIdx + 1));
                dfs(s,i + 1);
                current.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        dfs(s,0);
        return result;
    }
};
