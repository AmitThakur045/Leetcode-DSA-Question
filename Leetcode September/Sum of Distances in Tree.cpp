class Solution {
public:
    vector<unordered_set<int>> tree;
    vector<int> cnt, res;
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        tree.resize(n);       // Adjancy List
        cnt.resize(n, 1), res.resize(n, 0);   // cnt -> count the number of subtree and res -> count the answer for each Tree
        for (auto e : edges)
            tree[e[0]].insert(e[1]), tree[e[1]].insert(e[0]);
        
        dfs(0, -1);
        dfs2(0, -1);
        
        return res;
    }
    
    void dfs(int node, int prev) {
        for (int i : tree[node]) {
            if (i == prev) continue;
            dfs(i, node);
            cnt[node] += cnt[i];
            res[node] += res[i] + cnt[i];
        }
    }
    
    void dfs2(int node, int prev) {
        for (int i : tree[node]) {
            if (i == prev) continue;
            res[i] = res[node] - cnt[i] + cnt.size() - cnt[i];
            dfs2(i, node);
        }
    }
    
};
