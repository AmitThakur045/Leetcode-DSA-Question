class Solution {
public:
    int maxHistogram(vector<int>& a) {
        if(a.size() <= 0)
            return 0;
        int n = a.size();
        int ans = 0;
        
        for(int i=0; i<n; i++) {
            int r = i, l = i;
            while(r >= 0) {
                if(a[i] <= a[r]) {
                    r--;
                } else
                    break;
            }
            while(l < n) {
                if(a[i] <= a[l]) {
                    l++;
                } else 
                    break;
            }
            ans = max(a[i] * (l - r - 1), ans);
        }
        return ans;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() <= 0 || matrix[0].size() <= 0)
            return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<int> arr(m, 0);
        int res = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(matrix[i][j] == '1') {
                    arr[j]++;
                } else {
                    arr[j] = 0;
                }
            }
            int ans = maxHistogram(arr);
            // cout<<ans<<endl;
            res = max(res, ans);
        }
        return res;
    }
};
