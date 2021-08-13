class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mp;
        
        for(auto it : strs)  {
            string tmp = it;
            sort(tmp.begin(), tmp.end());
            mp[tmp].push_back(it);
        }
        
        for(auto it : mp) {
            res.push_back(it.second);;
        }
        return res;
    }
};
