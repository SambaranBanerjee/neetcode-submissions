class TrieNode {
public:
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class PrefixTree {
private:
    TrieNode* root;
public:
    PrefixTree() {
       root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for (int i = 0; i < word.size(); i++) {
            if (curr->children[word[i] - 'a'] == nullptr) {
                TrieNode* newNode = new TrieNode();
                curr->children[word[i] - 'a'] = newNode; 
            }
            curr = curr->children[word[i] - 'a'];
        }
        curr->isEndOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for (char ch : word) {
            if (curr->children[ch - 'a'] == nullptr) {
                return false;
            }
            curr = curr->children[ch - 'a'];
        }
        return curr->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (char ch : prefix) {
            if (curr->children[ch - 'a'] == nullptr) {
                return false;
            }
            curr = curr->children[ch - 'a'];
        }
        return true;
    }
};
