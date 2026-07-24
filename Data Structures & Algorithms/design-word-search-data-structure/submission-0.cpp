class TrieNode {
    public:
        TrieNode* children[26];
        bool isEndOfWord;
        TrieNode () {
            isEndOfWord = false;
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
};

class WordDictionary {
private:
    TrieNode* root;
    bool searchDFS(const string& word, int index, TrieNode* curr) {
        if (curr == nullptr) 
            return false;
        if (index == word.size())
            return curr->isEndOfWord;

        char ch = word[index];

        if (ch == '.') {
            for(int i = 0; i < 26; i++) {
                if (curr->children[i] != nullptr) {
                    if (searchDFS(word, index + 1, curr->children[i])) {
                        return true;
                    }
                }
            }
            return false;
        }
        else{
            int idx = ch - 'a';
            if (curr->children[idx] == nullptr) {
                return false;
            }
            return searchDFS(word, index + 1, curr->children[idx]);
        }
    }
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (curr->children[idx] == nullptr) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->isEndOfWord = true;
    }
    
    bool search(string word) {
        return searchDFS(word,0,root);
    }
};
