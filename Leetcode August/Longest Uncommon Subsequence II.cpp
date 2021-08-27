class Solution {
public:
    bool is_subsequence(string s1, string s2) {
        if(s1.size() > s2.size())
            return false;
        int i = 0;
        for(auto it : s2) {
            if(i < s1.size() && s1[i] == it)
                i++;
        }
        return i == s1.size();
    }
    
    int findLUSlength(vector<string>& strs) {
        if(strs.empty())
            return -1;
        int res = -1;
        for(int i=0; i<strs.size(); i++) {
            bool flag = 0;
            int curr_len = strs[i].size();
            
            for(int j=0; j<strs.size(); j++) {
                if(i == j)
                    continue;
                if(is_subsequence(strs[i], strs[j])) {
                    flag = true;
                }
            }
            if(!flag) {
                res = max(res, curr_len);
            }
        }
        return res;
    }
};
