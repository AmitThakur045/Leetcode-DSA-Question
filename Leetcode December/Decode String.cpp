class Solution {
public:
    string solve(int& pos, string s) {
        string word = "";
        int num = 0;
        
        for(; pos<s.size(); pos++) {
            char ch = s[pos];
            if(ch == '[') {
                string res = solve(++pos, s);
                for(; num>0; num--)
                    word += res;
            } else if(ch >= '0' && ch <= '9') {
                num = num * 10 + (ch - '0');
            } else if(ch == ']') {
                return word;
            } else {
                word += ch;
            }
        }
        return word;
    }
    
    string decodeString(string s) {
        int pos = 0;
        return solve(pos, s);
    }
};
