class Solution {
    bool checkCycle(int node, vector<int> adj[], int vis[], int dfsVis[]) {
        vis[node] = 1; 
        dfsVis[node] = 1; 
        for(auto it : adj[node]) {
            if(!vis[it]) {
                if(checkCycle(it, adj, vis, dfsVis)) return true;
            } else if(dfsVis[it]) {
                return true; 
            }
        }
        dfsVis[node] = 0; 
        return false;
    }
    bool isCyclic(int N, vector<int> adj[]) {
	   int vis[N], dfsVis[N]; 
	   memset(vis, 0, sizeof vis); 
	   memset(dfsVis, 0, sizeof dfsVis); 
	   
	   for(int i = 0;i<N;i++) {
	       if(!vis[i]) {
	           // cout << i << endl; 
	           if(checkCycle(i, adj, vis, dfsVis)) {
	               return true; 
	           }
	       }
	   }
	   return false; 
	}
public:
    stack<int> st;
    void dfs(vector<int> adj[], int node, vector<bool>& vis) {
        vis[node] = true;
        for(auto &i : adj[node]) {
            if(!vis[i]) {
                dfs(adj, i, vis);
            }
        }
        st.push(node);
    }
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int> adj[n];
        for(auto &i : prerequisites) {
            adj[i[1]].push_back(i[0]);
        }
        
        vector<int> ans;
        if(isCyclic(n, adj)) {
            return ans;
        }
        
        vector<bool> vis(n, false);
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                dfs(adj, i, vis);
            }
        }
    
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
