class Solution {
public:
    bool solve(vector<int>& arr, int start, vector<bool>& vis) {
        if(start < 0 || start >= arr.size() || vis[start] == true)
            return false;
        int val = arr[start];
        if(val == 0)
            return true;
        vis[start] = true;
        return (solve(arr, start - val, vis) || solve(arr, start + val, vis));
    }
    bool canReach(vector<int>& arr, int start) {
        vector<bool> vis(arr.size(), false);
        return solve(arr, start, vis);
    }
};
