class Solution {
    vector<vector<string>> result;
    unordered_set<int> cols;
    unordered_set<int> posDiag; // (r + c)
    unordered_set<int> negDiag; // (r - c)

    void dfs(int r, int n, vector<string>& board) {
        if (r == n) {
            result.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) {
            if (cols.count(c) || posDiag.count(r + c) || negDiag.count(r - c)) {
                continue;
            }

            //Modify / Place Queen
            cols.insert(c);
            posDiag.insert(r + c);
            negDiag.insert(r - c);
            board[r][c] = 'Q';

            //Explore
            dfs(r + 1,n,board);

            //Backtrack
            cols.erase(c);
            posDiag.erase(r + c);
            negDiag.erase(r - c);
            board[r][c] = '.';

        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        dfs(0,n,board);
        return result;
    }
};
