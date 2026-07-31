class Solution {
private:
    vector<string> result;
    void dfs (int n, int openCount, int closedCount, string& current) {
        if (openCount == n && closedCount == n) {
            result.push_back(current);
            return;
        }

        if (openCount < n) {
            current.push_back('(');
            dfs(n,openCount + 1,closedCount,current);
            current.pop_back();
        }
        if (closedCount < openCount) {
            current.push_back(')');
            dfs(n,openCount,closedCount + 1,current);
            current.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        string current = "";
        dfs(n,0,0,current);
        return result;
    }
};
