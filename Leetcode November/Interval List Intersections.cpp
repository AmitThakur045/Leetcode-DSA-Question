class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& first, vector<vector<int>>& second) {
        int n1 = first.size();
        int n2 = second.size();
        vector<vector<int>> res;
        
        int i = 0, j = 0; 
        while(i < n1 && j < n2) {
            int left = max(first[i][0], second[j][0]);
            int right = min(first[i][1], second[j][1]);
            
            if(left <= right) {
                vector<int> ans(2);
                ans[0] = left;
                ans[1] = right;
                res.push_back(ans);
            }
            
            if(first[i][1] < second[j][1]) {
                i++;
            } else {
                j++;
            }
            
            // cout<<"i: "<<i<<" j: "<<j<<endl;
        }
        
        return res;
    }
};
