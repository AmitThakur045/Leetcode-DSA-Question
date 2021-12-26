class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 0)
            return {};
        
        vector<set<int>> adj(n);
        for(auto i : edges) {
            adj[i[0]].insert(i[1]);
            adj[i[1]].insert(i[0]);
        }
        
        vector<int> curr;
        if(n == 1) {
            curr.push_back(0);
            return curr;
        }
        
        for(int i=0; i<adj.size(); i++) {
            if(adj[i].size() == 1)
                curr.push_back(i);
        }
        
        while(true) {
            vector<int> ans;
            for(auto i : curr) {
                for(auto node : adj[i]) {
                    adj[node].erase(i);
                    if(adj[node].size() == 1)
                        ans.push_back(node);
                }
            }
            if(ans.empty())
                return curr;
            curr = ans;
        }
    }
};
