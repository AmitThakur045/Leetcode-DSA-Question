class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<vector<int>> res;
        
        int mini = INT_MAX;
        for(int i=1; i<n; i++) {
            int sub = arr[i] - arr[i-1];
            mini = min(mini, sub);
        }
        
        for(int i=1; i<n; i++) {
            if(arr[i] - arr[i-1] == mini) {
                vector<int> ans;
                ans.push_back(arr[i-1]);
                ans.push_back(arr[i]);
                res.push_back(ans);
            }
        }
        return res;
    }
};
