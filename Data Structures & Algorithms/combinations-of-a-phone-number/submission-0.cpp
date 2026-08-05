class Solution {
private:
    vector<string> result;
    string current;

    const vector<string> pad = {
        "","", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void dfs(int digitIdx, string digits) {
        if (digitIdx == digits.size()) {
            result.push_back(current);
            return;
        }

        string letters = pad[digits[digitIdx] - '0'];

        for (int i = 0; i < letters.size(); i++) {
            current.push_back(letters[i]); //Modify
            dfs(digitIdx + 1, digits); //Explore
            current.pop_back(); //Backtrack
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        dfs(0,digits);
        return result;
    }
};
