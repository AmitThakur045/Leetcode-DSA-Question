class Solution {
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};
    
    int dfs(vector<vector<int>>& grid, int i, int j, int m, int n, int &zero) {
        // cout<<i<<" "<<j<<endl;
        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == -1)
            return 0;
        if(grid[i][j] == 2) {
            return zero == -1 ? 1 : 0;
        }
        
        grid[i][j] = -1;
        zero--;
        int total = 0;
        for(int k=0; k<4; k++) {
            int nx = i + dx[k];
            int ny = j + dy[k];
            total += dfs(grid, nx, ny, m, n, zero);
        }
        grid[i][j] = 0;
        zero++;
        
        return total;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        // vector<vector<int>> res;
        // vector<int> ans;
        
        int _i = 0, _j = 0, zero = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    _i = i;
                    _j = j;
                } else if(grid[i][j] == 0)
                    zero++;
            }
        }
        
        return dfs(grid, _i, _j, m, n, zero);
        // return 4;
    }
};
