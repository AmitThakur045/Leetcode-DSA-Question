class Solution {
public:
    vector<vector<int>> res;
    void dfs(int node, int par, vector<int> adj[], vector<int>& ans, int m) {
        if(node == m-1) {
            ans.push_back(node);
            res.push_back(ans);
            ans.pop_back();
            return;
        }
        
        for(auto i : adj[node]) {
            ans.push_back(node);
            dfs(i, node, adj, ans, m);
            ans.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int m = graph.size();
        
        vector<int> adj[m];
        for(int i=0; i<m; i++) {
            adj[i] = graph[i];
        }
        
        for(auto i : adj[0]) {
            vector<int> ans;
            ans.push_back(0);
            dfs(i, 0, adj, ans, m);    
        }
        
        return res;
    }
};
