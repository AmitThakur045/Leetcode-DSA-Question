class CombinationIterator {
    vector<string> res;
    int ptr;

    void solve(string s, int n, int pos, int len, string tmp) {
        if(len == 0) {
            res.push_back(tmp);
            return;
        }
        if(pos >= n) {
            return;
        }
    
        tmp += s[pos];
        solve(s, n, pos+1, len-1, tmp);
        tmp.pop_back();
        solve(s, n, pos+1, len, tmp);
    }
public:
    CombinationIterator(string characters, int combinationLength) {
        solve(characters, characters.size(), 0, combinationLength, "");
        ptr = 0;
    }
    
    string next() {
        return res[ptr++];
    }
    
    bool hasNext() {
        return ptr < res.size() ? true : false;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
