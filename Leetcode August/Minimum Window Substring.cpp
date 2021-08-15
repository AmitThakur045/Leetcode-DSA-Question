class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() == 0 || t.size() == 0)
            return "";
        
        vector<int> tmp(128, 0);
        int t_size = t.size();
        for(int i=0; i<t_size; i++) {
            tmp[t[i]]++;
        }
        
        int len = INT_MAX, start = 0, i = 0, left = 0;
        while(i <= s.size() && start < s.size()) {
            if(t_size) {
                if(i == s.size())
                    break;
                tmp[s[i]]--;
                if(tmp[s[i]] >= 0)
                    t_size--;
                i++;
            }
            else {
                if(i - start < len) {
                    len = i - start;
                    left = start;
                }
                tmp[s[start]]++;
                if(tmp[s[start]] > 0)
                    t_size++;
                start++;
            }
        }
        return len == INT_MAX ? "" : s.substr(left, len);
        
    }
};
