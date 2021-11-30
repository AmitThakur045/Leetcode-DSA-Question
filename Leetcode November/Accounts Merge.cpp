class Solution {
public:
    int find(vector<int>& par, int x) {
        while(par[x] != x) {
            x = par[x];
        }    
        return x;
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> mp;
        int n = accounts.size();
        vector<int> par(n, 0);
        
        for(int i=0; i<n; i++) {
            par[i] = i;
            auto emails = accounts[i];
            for(int j=1; j<emails.size(); j++) {
                if(mp.find(emails[j]) != mp.end()) {
                    int node1 = find(par, i);
                    int node2 = find(par, mp[emails[j]]);
                    par[node2] = node1;
                } else {
                    mp[emails[j]] = par[i];
                }
            }
        }
        
        unordered_map<int, vector<string>> res;
        for(auto i : mp) {
            int idx = find(par, i.second);
            res[idx].push_back(i.first);
        }
        
        vector<vector<string>> ans;
        for(auto i : res) {
            vector<string> tmp = i.second;
            sort(tmp.begin(), tmp.end());
            tmp.insert(tmp.begin(), accounts[i.first][0]);
            ans.push_back(tmp);
        }
        return ans;
    }
};
