struct Node {
    Node* links[26];
    bool flag = false;
    
    bool containskey(char ch) {
        return links[ch - 'a'];
    }
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }
    Node* get(char ch) {
        return links[ch - 'a'];
    }
    void setEnd() {
        flag = true;
    }
    bool isEnd() {
        return flag;
    }
};

class StreamChecker {
private:
    string querys = "";
    Node* root;
private:
    void insert(string s) {
        Node* node = root;
        for(int i=s.size()-1; i>=0; i--) {
            if(!node->containskey(s[i])) {
                node->put(s[i], new Node());
            }
            node = node->get(s[i]);
        }
        node->setEnd();
    }
public:
    StreamChecker(vector<string>& words) {
        root = new Node();
        for(auto &it : words) {
            insert(it);
        } 
    }
    
    bool query(char letter) {
        querys += letter;
        Node* node = root;
        for(int i=querys.size()-1; i>=0; i--) {
            if(node->containskey(querys[i])) {
                node = node->get(querys[i]);
                if(node->isEnd())   return true;
            } else {
                return false;
            }
        }
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
