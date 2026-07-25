
struct TrieNode {
    TrieNode* children[26];
    string word;

    TrieNode () {
        word = "";
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Solution {
private:
    TrieNode* root;
    vector<string> result;
    void insert(const string& word) {
        TrieNode* curr = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (curr->children[idx] == nullptr) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->word = word;
    }

    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node) {
        char ch = board[r][c];
        int idx = ch - 'a';
        if (ch == '#' || node->children[idx] == nullptr) {
            return;
        }

        node = node->children[idx];

        if (!node->word.empty()) {
            result.push_back(node->word);
            node->word = "";
        }
        board[r][c] = '#';

        int dr[4] = {-1,1,0,0};
        int dc[4] = {0,0,-1,1};

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < board.size() && nc >= 0 && nc < board[0].size()) {
                dfs(board,nr,nc,node);
            }
        }

        board[r][c] = ch;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();
        
        for (const string& w : words) {
            insert(w);
        }         

        int rows = board.size();
        int columns = board[0].size();
        
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < columns; c++) {
                dfs(board, r, c, root);
            }
        }

        return result;
    }
};
