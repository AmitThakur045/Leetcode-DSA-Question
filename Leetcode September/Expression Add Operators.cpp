class Solution {
public:
    vector<string> ans;
    int target;
    string s;
    vector<string> addOperators(string s, int target) {
        this->target = target;
        this->s = s;
        
        string path = "";
        dfs(0, path, 0, 0);
        return ans;
    }
    
    void dfs(int i, string path, long res, long prev) {
        if(i == s.size()) {
            if(res == target)
                ans.push_back(path);
            return;
        }
        
        long num = 0;
        string tmp;
        for(int j=i; j<s.size(); j++) {
            if(j > i && s[i] == '0') break;
            num = num*10 + s[j] - '0';
            tmp += s[j];
            if(i == 0) {
                dfs(j+1, path + tmp, res + num, num);
            } else {
                dfs(j+1, path + "+" + tmp, res + num, num);
                dfs(j+1, path + "-" + tmp, res - num, -num);
                dfs(j+1, path + "*" + tmp, res - prev + prev * num, prev * num);
            }
        }
    }
};
