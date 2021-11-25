class Solution {
public:
    int par[100001];
    int find(int x) {
        if(par[x] == -1)
            return x;
        else {
            return par[x] = find(par[x]);
        }
    }
    
    void Union(int x, int y) {
        int xp = find(x);
        int yp = find(y);
        
        if(xp != yp) {
            par[yp] = xp;
        }
    }
    
    int largestComponentSize(vector<int>& nums) {
        unordered_map<int, int> mp; 
        memset(par, - 1, sizeof(par));
        int res = 0;
        for(auto x : nums) {
            for(int i=2; i*i <= x; i++) {
                if(x % i == 0) {
                    Union(x, i);
                    Union(x, x/i);
                }
            }
        }
        
        for(auto i: nums) {
            res = max(res, ++mp[find(i)]);
        }
        
        return res;
    }
};
