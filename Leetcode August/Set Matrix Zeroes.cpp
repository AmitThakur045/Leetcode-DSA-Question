class Solution {
public:
    void col(vector<vector<int>>& mat, int j, int& m) {
        for(int i=0; i<m; i++) {
            mat[i][j] = 0;
        }
    }
    
    void row(vector<vector<int>>& mat, int i, int& n) {
        for(int j=0; j<n; j++) {
            mat[i][j] = 0;
        }
    } 
        
    void setZeroes(vector<vector<int>>& mat) {
        vector<pair<int,int>> v;
        int m = mat.size();
        int n = mat[0].size();
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(mat[i][j] == 0)
                    v.push_back({i,j});
            }
        }
        
        for(int k=0; k<v.size(); k++) {
            int i = v[k].first;
            int j = v[k].second;
            row(mat, i, n);
            col(mat, j, m);
        }
    }
}; 
