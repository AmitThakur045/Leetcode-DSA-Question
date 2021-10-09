class Solution {
    struct TrieNode {
        TrieNode *child[26];
        string word;
        
        TrieNode() : word("") {
            for(int i=0; i<26; i++) {
                child[i] = nullptr;
            }
        }
    };
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = buildTrie(words);
        vector<string> result;
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                dfs(i, j, board, result, root);
            }
        }
        return result;
    }
    
    TrieNode* buildTrie(vector<string>&words) {
        TrieNode *root = new TrieNode();
        for(auto s : words) {
            TrieNode* curr = root;
            for(int i=0; i<s.size(); i++) {
                if(curr->child[s[i] - 'a'] == nullptr)
                    curr->child[s[i] - 'a'] = new TrieNode();
                curr = curr->child[s[i] - 'a'];
            }
            curr->word = s;
        }
        return root;
    }
    
    void dfs(int i, int j, vector<vector<char>>& board, vector<string>& res, TrieNode* node) {
        char c = board[i][j];
        if(c == '#' || !node->child[c - 'a'])
            return;
        node = node->child[c - 'a'];
        if(node->word.size() > 0) {
            res.push_back(node->word);
            node->word = "";
        }
        
        board[i][j] = '#';
        if(i > 0)   dfs(i-1, j, board, res, node);
        if(j > 0)   dfs(i, j-1, board, res, node);
        if(i < board.size()-1)  dfs(i+1, j, board, res, node);
        if(j < board[0].size() - 1) dfs(i, j+1, board, res, node); 
        board[i][j] = c;
    }
    
};
