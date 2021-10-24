class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int, char>> mp('z' + 1, {0, 0});
        for(auto i : s) {
            mp[i] = {mp[i].first + 1, i};
        }
        
        sort(mp.begin(), mp.end());
        
        string res = "";
        for(auto i : mp) {
            res = string(i.first, i.second) + res;
        }
        return res;
    }
};
