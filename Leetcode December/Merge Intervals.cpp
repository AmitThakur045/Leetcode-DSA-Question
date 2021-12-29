class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<int> res;
        res.push_back(intervals[0][0]);
        res.push_back(intervals[0][1]);
        
        int n = intervals.size();
        vector<vector<int>> ans;
        for(int i=1; i<n; i++) {
            if(res[1] < intervals[i][0]) {
                ans.push_back(res);
                res[0] = intervals[i][0];
                res[1] = intervals[i][1];
            } else {
                if(res[1] < intervals[i][1]) {
                    res[1] = intervals[i][1];
                }
            }
        }
        ans.push_back(res);
        return ans;
    }
};
